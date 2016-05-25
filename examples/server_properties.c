/* Example Project which creates an opc ua server application. The server contains the property model that allows to create properties, link them to a carrier and create statements.
*/
#include <signal.h>
#include <stdlib.h>

#ifdef UA_NO_AMALGAMATION
# include "ua_types.h"
# include "ua_server.h"
# include "ua_config_standard.h"
# include "networklayer_tcp.h"
#else
# include "open62541.h"
#endif

/* files nodeset.h and nodeset.c are created from server_nodeset.xml in the /src_generated directory by CMake */
#include "nodeset.h"

UA_Logger logger = Logger_Stdout;
UA_Boolean running = true;

static void stopHandler(int sign) {
    UA_LOG_INFO(logger, UA_LOGCATEGORY_SERVER, "received ctrl-c");
    running = false;
}
static UA_StatusCode getChildNodeId(UA_Server *server, const UA_NodeId *parentNodeId,
        UA_NodeId referenceTypeId, UA_QualifiedName *browseName,
        UA_UInt32 expectedRefCount, UA_NodeId *foundNodeId) {
    UA_StatusCode retval = UA_STATUSCODE_GOOD;
    //set value value of property name
    UA_BrowseDescription *descr = UA_BrowseDescription_new();
    UA_BrowseDescription_init(descr);
    descr->browseDirection = UA_BROWSEDIRECTION_FORWARD;
    descr->includeSubtypes = false;
    descr->nodeClassMask = 3;
    descr->nodeId = *parentNodeId;
    descr->referenceTypeId = referenceTypeId;
    descr->resultMask = UA_BROWSERESULTMASK_ALL;

    UA_BrowseResult browseRes = UA_Server_browse(server, expectedRefCount, descr);

    if (browseRes.referencesSize < expectedRefCount) {
        retval = UA_STATUSCODE_BADINTERNALERROR;
        goto clean_up;
    }
    UA_ExpandedNodeId tmpfoundNodeId;
    UA_Boolean foundNode = false;
    for (size_t i = 0; i < browseRes.referencesSize; i++) {
        if (UA_String_equal(&browseRes.references[i].browseName.name,
                &browseName->name)) {
            foundNode = true;
            tmpfoundNodeId = browseRes.references[i].nodeId;
            break;
        }
    }

    if (foundNode == false) {
        retval = UA_STATUSCODE_BADINTERNALERROR;
    }

    *foundNodeId = tmpfoundNodeId.nodeId;
    clean_up: UA_BrowseDescription_delete(descr);
    return retval;
}

static void setSubNodeValue(UA_Server* server,UA_QualifiedName* subNodeName, const UA_NodeId* parentNode,const void* value,const UA_DataType* type) {
    UA_NodeId subNode;
    if (getChildNodeId(server, parentNode,
            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT), subNodeName, 10,
            &subNode)==UA_STATUSCODE_GOOD) {
        UA_Variant v;
        UA_Variant_init(&v);
        UA_Variant_setScalarCopy(&v, value, type);
        UA_Server_writeValue(server, subNode, v);
    }
}

static UA_StatusCode createPropertyValueStatement(void *handle, const UA_NodeId objectId,
        size_t inputSize, const UA_Variant *input, size_t outputSize,
        UA_Variant *output) {

    UA_StatusCode retval = UA_STATUSCODE_GOOD;
    // get property's root node (id)
    UA_NodeId *parentNodeId = (UA_NodeId*) (input[0].data);
    // get property's alias name
    UA_String *value = (UA_String*) (input[1].data);
    //get unit
    UA_String *unit = (UA_String*) (input[2].data);
   //upper deviation
    UA_Double *deviationUp = (UA_Double*) (input[3].data);
    //lower deviaton
    UA_Double *deviationDown = (UA_Double*) (input[4].data);
    //relation expression
    UA_Int32 *statementExpressionRelational = (UA_Int32*) (input[5].data);
    //statement semantics
    UA_Int32 *statementSemantics = (UA_Int32*) (input[6].data);
    //valid from
    UA_DateTime *validFrom = (UA_DateTime*) (input[7].data);
    //valid until
    UA_DateTime *validUntil = (UA_DateTime*) (input[8].data);

    UA_Server* server = (UA_Server*) handle;

    UA_ObjectAttributes objAtr;
    UA_ObjectAttributes_init(&objAtr);
    UA_QualifiedName browseName;
    browseName.namespaceIndex = 0;
    UA_String tmpName;
    switch(*statementSemantics){
    case 0:tmpName = UA_STRING("Requirement"); break;
    case 1:tmpName = UA_STRING("Assurance"); break;
    case 2:tmpName = UA_STRING("Measurement"); break;
    }

    UA_String_copy(&tmpName, &browseName.name);

    UA_String_copy(&tmpName, &objAtr.displayName.text);
    objAtr.displayName.locale = UA_STRING_ALLOC("en");

    UA_NodeId refTypeNodeId = UA_NODEID_NUMERIC(2, 24003); //HasPropertyValueStatement
    UA_NodeId typeNodeId = UA_NODEID_NUMERIC(2, 21004); //PropertyValueStatementType
    UA_NodeId newNodeId = UA_NODEID_NUMERIC(1, 10223); // random Id
    UA_NodeId createdNodeId;
    UA_QualifiedName qname;
    while(UA_Server_readBrowseName(server,newNodeId,&qname)==UA_STATUSCODE_GOOD){
        if(newNodeId.identifier.numeric>=INT32_MAX){
            retval = UA_STATUSCODE_BADINTERNALERROR;
            goto clean_up;
        }
        newNodeId.identifier.numeric++;
    }

    retval = UA_Server_addObjectNode(server, newNodeId, *parentNodeId,
            refTypeNodeId, browseName, typeNodeId, objAtr, NULL,
            &createdNodeId);
    if(retval!=UA_STATUSCODE_GOOD)
        goto clean_up;


    //UA_NodeId foundNodeId;
    //set values

    UA_QualifiedName qn = UA_QUALIFIEDNAME(0, "Value");
    setSubNodeValue(server,&qn,&createdNodeId,value,&UA_TYPES[UA_TYPES_STRING]);

    qn = UA_QUALIFIEDNAME(0, "Unit");
    setSubNodeValue(server,&qn,&createdNodeId,unit,&UA_TYPES[UA_TYPES_STRING]);

    qn = UA_QUALIFIEDNAME(0, "DeviationUp");
    setSubNodeValue(server,&qn,&createdNodeId,deviationUp,&UA_TYPES[UA_TYPES_DOUBLE]);

    qn = UA_QUALIFIEDNAME(0, "DeviationDown");
    setSubNodeValue(server,&qn,&createdNodeId,deviationDown,&UA_TYPES[UA_TYPES_DOUBLE]);

    qn = UA_QUALIFIEDNAME(0, "RelationalExpression");
    setSubNodeValue(server,&qn,&createdNodeId,statementExpressionRelational,&UA_TYPES[UA_TYPES_INT32]);

    qn = UA_QUALIFIEDNAME(0, "SemanticExpression");
    setSubNodeValue(server,&qn,&createdNodeId,statementSemantics,&UA_TYPES[UA_TYPES_INT32]);

    qn = UA_QUALIFIEDNAME(0, "ValidFrom");
    setSubNodeValue(server,&qn,&createdNodeId,validFrom,&UA_TYPES[UA_TYPES_DATETIME]);


    qn = UA_QUALIFIEDNAME(0, "ValidUntil");
    setSubNodeValue(server,&qn,&createdNodeId,validUntil,&UA_TYPES[UA_TYPES_DATETIME]);

    UA_String tmp;
    clean_up:
    tmp = UA_STRING_ALLOC("Done");

    UA_Variant_setScalarCopy(output, &tmp, &UA_TYPES[UA_TYPES_STRING]);
    UA_String_deleteMembers(&tmp);
    UA_LOG_INFO(logger, UA_LOGCATEGORY_SERVER, "CreateProperty was called");
    return retval;

}

static UA_StatusCode createProperty(void *handle, const UA_NodeId objectId,
        size_t inputSize, const UA_Variant *input, size_t outputSize,
        UA_Variant *output) {
    UA_StatusCode retval = UA_STATUSCODE_GOOD;
    // get property's root node (id)
    UA_NodeId *parentNodeId = (UA_NodeId*) (input[0].data);
    // get property's alias name
    UA_String *propertyAliasName = (UA_String*) (input[1].data);
    //get property's full name
    UA_String *propertyName = (UA_String*) (input[2].data);
    //get property's semantic identifier specification
    UA_String *propertySemanticIdSpec = (UA_String*) (input[3].data);
    //get property's semantic identifier type
    UA_Int32 *propertySemanticIdType = (UA_Int32*) (input[4].data);

    UA_Server* server = (UA_Server*) handle;

    UA_ObjectAttributes objAtr;
    UA_ObjectAttributes_init(&objAtr);
    UA_QualifiedName browseName;
    browseName.namespaceIndex = 0;
    UA_String_copy(propertyAliasName, &browseName.name);

    UA_String_copy(propertyAliasName, &objAtr.displayName.text);
    objAtr.displayName.locale = UA_STRING_ALLOC("en");

    UA_NodeId refTypeNodeId = UA_NODEID_NUMERIC(2, 24002); //HasPropertyRef
    UA_NodeId typeNodeId = UA_NODEID_NUMERIC(2, 21002); //PropertyType
    UA_NodeId newNodeId = UA_NODEID_NUMERIC(1, 10000); // random Id
    UA_NodeId createdNodeId;
    UA_NodeId foundNodeId;
    UA_QualifiedName qname;

    while(UA_Server_readBrowseName(server,newNodeId,&qname)==UA_STATUSCODE_GOOD){
        if(newNodeId.identifier.numeric>=INT32_MAX){
            retval = UA_STATUSCODE_BADINTERNALERROR;
            goto clean_up;
        }
        newNodeId.identifier.numeric++;
    }

    retval = UA_Server_addObjectNode(server, newNodeId, *parentNodeId,
            refTypeNodeId, browseName, typeNodeId, objAtr, NULL,
            &createdNodeId);
    if(retval!=UA_STATUSCODE_GOOD)
        goto clean_up;
    //TODO following operations could be encapsulated within a constructor
    UA_Variant v;
    UA_Variant_init(&v);
    v.arrayDimensions = NULL;
    v.arrayDimensionsSize = 0;
    v.arrayLength = 0;

    UA_QualifiedName qn = UA_QUALIFIEDNAME(0, "PropertyName");

    setSubNodeValue(server,&qn,&createdNodeId,propertyName,&UA_TYPES[UA_TYPES_STRING]);

    qn = UA_QUALIFIEDNAME(0, "SemanticIdentifier");
    if (getChildNodeId(server, &createdNodeId,
            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT), &qn, 2,
            &foundNodeId)!=UA_STATUSCODE_GOOD) {
        retval = UA_STATUSCODE_BADINTERNALERROR;
        goto clean_up;
    }
    UA_NodeId nodeIdSemanticId = foundNodeId;
    qn = UA_QUALIFIEDNAME(0, "IDspec");
    setSubNodeValue(server,&qn,&foundNodeId,propertySemanticIdSpec,&UA_TYPES[UA_TYPES_STRING]);
    qn = UA_QUALIFIEDNAME(0, "IDtype");
    setSubNodeValue(server,&qn,&nodeIdSemanticId,propertySemanticIdType,&UA_TYPES[UA_TYPES_INT32]);



    UA_String tmp;
    clean_up:

    tmp = UA_STRING_ALLOC("Done");
    UA_Variant_setScalarCopy(output, &tmp, &UA_TYPES[UA_TYPES_STRING]);
    UA_String_deleteMembers(&tmp);
    UA_LOG_INFO(logger, UA_LOGCATEGORY_SERVER, "CreateProperty was called");
    return retval;
}

int main(int argc, char** argv) {
    signal(SIGINT, stopHandler); /* catches ctrl-c */

    /* initialize the server */
    UA_ServerConfig config = UA_ServerConfig_standard;
    UA_ServerNetworkLayer nl = UA_ServerNetworkLayerTCP(
            UA_ConnectionConfig_standard, 16664);
    config.networkLayers = &nl;
    config.networkLayersSize = 1;
    UA_Server *server = UA_Server_new(config);

    /* create nodes from nodeset */
    nodeset(server);




//create method node for property creation
    UA_NodeId newNodeId     = UA_NODEID_NUMERIC(1, 101);
    UA_NodeId parentNodeId = UA_NODEID_NUMERIC(0, 2253);

    UA_MethodAttributes methAtr;
    UA_MethodAttributes_init(&methAtr);
    methAtr.description = UA_LOCALIZEDTEXT("en",
            "Creates a property for to a given property carrier");
    methAtr.displayName = UA_LOCALIZEDTEXT("en", "createProperty");
    methAtr.executable = true;
    methAtr.userExecutable = true;

    UA_QualifiedName createPropertyMethodBrowseName = UA_QUALIFIEDNAME(1,
            "createProperty");
    UA_Argument* inArgs = UA_Array_new(5, &UA_TYPES[UA_TYPES_ARGUMENT]);
    for (int i = 0; i < 5; i++) {
        UA_Argument_init(&inArgs[i]);
    }
    //node id property carrier
    inArgs[0].arrayDimensionsSize = 0;
    inArgs[0].name = UA_STRING_ALLOC("Property Carrier NodeId");
    inArgs[0].dataType = UA_TYPES[UA_TYPES_NODEID].typeId;
    inArgs[0].description = UA_LOCALIZEDTEXT("en",
            "Node Id of property Carrier");
    inArgs[0].valueRank = -1;
    inArgs[0].arrayDimensionsSize = 0;

    //property alias name
    inArgs[1].arrayDimensionsSize = 0;
    inArgs[1].name = UA_STRING_ALLOC("Property AliasName");
    inArgs[1].dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    inArgs[1].description = UA_LOCALIZEDTEXT("en",
            "Short/Aliasname of property");
    inArgs[1].valueRank = -1;
    inArgs[1].arrayDimensionsSize = 0;

    //property full name
    inArgs[2].arrayDimensionsSize = 0;
    inArgs[2].name = UA_STRING_ALLOC("Property FullName");
    inArgs[2].dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    inArgs[2].description = UA_LOCALIZEDTEXT("en", "Full name of property");
    inArgs[2].valueRank = -1;
    inArgs[2].arrayDimensionsSize = 0;

    //property Semantic identifier specification
    inArgs[3].arrayDimensionsSize = 0;
    inArgs[3].name = UA_STRING_ALLOC("Property SemanticIdentifier Specification");
    inArgs[3].dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    inArgs[3].description = UA_LOCALIZEDTEXT("en",
            "Property semantic identifier specification");
    inArgs[3].valueRank = -1;
    inArgs[3].arrayDimensionsSize = 0;

    //property Semantic identifier type
    inArgs[4].arrayDimensionsSize = 0;
    inArgs[4].name = UA_STRING_ALLOC("Property Semantic Identifier Type");
    inArgs[4].dataType = UA_NODEID_NUMERIC(2, 23002);
    inArgs[4].description = UA_LOCALIZEDTEXT("en",
            "Property semantic identifier type");
    inArgs[4].valueRank = -1;
    inArgs[4].arrayDimensionsSize = 0;

    UA_Argument *outArgs = UA_Array_new(1, &UA_TYPES[UA_TYPES_ARGUMENT]);
    outArgs[0].arrayDimensionsSize = 0;
    outArgs[0].name = UA_STRING_ALLOC("OutArg");
    outArgs[0].dataType = UA_TYPES[UA_TYPES_INT32].typeId;
    outArgs[0].description = UA_LOCALIZEDTEXT("en", "output");
    outArgs[0].valueRank = -1;
    outArgs[0].arrayDimensionsSize = 0;

    UA_Server_addMethodNode(server, newNodeId, parentNodeId,
            UA_NODEID_NUMERIC(0, UA_NS0ID_HASORDEREDCOMPONENT),
            createPropertyMethodBrowseName, methAtr, &createProperty,
            (void*) server, 5, inArgs, 1, outArgs, &newNodeId);


//Add method node for value statements
        newNodeId     = UA_NODEID_NUMERIC(1, 102);
        parentNodeId = UA_NODEID_NUMERIC(0, 2253);

        UA_MethodAttributes methAddStatementAtr;
        UA_MethodAttributes_init(&methAddStatementAtr);
        methAddStatementAtr.description = UA_LOCALIZEDTEXT("en",
                "Creates a value statement for to a given property");
        methAddStatementAtr.displayName = UA_LOCALIZEDTEXT("en", "createPropertyValueStatement");
        methAddStatementAtr.executable = true;
        methAddStatementAtr.userExecutable = true;

        UA_QualifiedName createPropertyValueStatementMethodBrowseName = UA_QUALIFIEDNAME(1,
                "createPropertyValueStatement");
        UA_Argument* inArgs1 = UA_Array_new(9, &UA_TYPES[UA_TYPES_ARGUMENT]);
        for (int i = 0; i < 9; i++) {
            UA_Argument_init(&inArgs[i]);
        }

        //node id property
        inArgs1[0].arrayDimensionsSize = 0;
        inArgs1[0].name = UA_STRING_ALLOC("Property NodeId");
        inArgs1[0].dataType = UA_TYPES[UA_TYPES_NODEID].typeId;
        inArgs1[0].description = UA_LOCALIZEDTEXT("en",
                "Node Id of property");
        inArgs1[0].valueRank = -1;
        inArgs1[0].arrayDimensionsSize = 0;

        //value //TODO atm only string values are possible
        inArgs1[1].arrayDimensionsSize = 0;
        inArgs1[1].name = UA_STRING_ALLOC("value");
        inArgs1[1].dataType = UA_TYPES[UA_TYPES_STRING].typeId;
        inArgs1[1].description = UA_LOCALIZEDTEXT("en",
                "Value of the statement");
        inArgs1[1].valueRank = -1;
        inArgs1[1].arrayDimensionsSize = 0;

        //unit
        inArgs1[2].arrayDimensionsSize = 0;
        inArgs1[2].name = UA_STRING_ALLOC("Unit");
        inArgs1[2].dataType = UA_TYPES[UA_TYPES_STRING].typeId;
        inArgs1[2].description = UA_LOCALIZEDTEXT("en",
                "Unit of the value");
        inArgs1[2].valueRank = -1;
        inArgs1[2].arrayDimensionsSize = 0;

        //deviation up
        inArgs1[3].arrayDimensionsSize = 0;
        inArgs1[3].name = UA_STRING_ALLOC("deviation up");
        inArgs1[3].dataType = UA_TYPES[UA_TYPES_DOUBLE].typeId;
        inArgs1[3].description = UA_LOCALIZEDTEXT("en",
                "Upper deviation of the value");
        inArgs1[3].valueRank = -1;
        inArgs1[3].arrayDimensionsSize = 0;

        //deviation down
        inArgs1[4].arrayDimensionsSize = 0;
        inArgs1[4].name = UA_STRING_ALLOC("deviation down");
        inArgs1[4].dataType = UA_TYPES[UA_TYPES_DOUBLE].typeId;
        inArgs1[4].description = UA_LOCALIZEDTEXT("en",
                "Lower deviation of the value");
        inArgs1[4].valueRank = -1;
        inArgs1[4].arrayDimensionsSize = 0;

        //relational expression type
        inArgs1[5].arrayDimensionsSize = 0;
        inArgs1[5].name = UA_STRING_ALLOC("relation expression type");
        inArgs1[5].dataType = UA_NODEID_NUMERIC(2, 23003);
        inArgs1[5].description = UA_LOCALIZEDTEXT("en",
             "relational expression");
        inArgs1[5].valueRank = -1;
        inArgs1[5].arrayDimensionsSize = 0;

         //semantic expression
        inArgs1[6].arrayDimensionsSize = 0;
        inArgs1[6].name = UA_STRING_ALLOC("relation expression type");
        inArgs1[6].dataType = UA_NODEID_NUMERIC(2, 23004);
        inArgs1[6].description = UA_LOCALIZEDTEXT("en",
              "Semantics of the statement");
        inArgs1[6].valueRank = -1;
        inArgs1[6].arrayDimensionsSize = 0;

        //Valid from
        inArgs1[7].arrayDimensionsSize = 0;
        inArgs1[7].name = UA_STRING_ALLOC("valid from");
        inArgs1[7].dataType = UA_TYPES[UA_TYPES_DATETIME].typeId;
        inArgs1[7].description = UA_LOCALIZEDTEXT("en",
              "The point in time from which the property value statement is valid");
        inArgs1[7].valueRank = -1;
        inArgs1[7].arrayDimensionsSize = 0;

        //Valid until
                inArgs1[8].arrayDimensionsSize = 0;
                inArgs1[8].name = UA_STRING_ALLOC("valid until");
                inArgs1[8].dataType = UA_TYPES[UA_TYPES_DATETIME].typeId;
                inArgs1[8].description = UA_LOCALIZEDTEXT("en",
                      "The point in time that represents the expiration time of a property");
                inArgs1[8].valueRank = -1;
                inArgs1[8].arrayDimensionsSize = 0;

        UA_Server_addMethodNode(server, newNodeId, parentNodeId,
                UA_NODEID_NUMERIC(0, UA_NS0ID_HASORDEREDCOMPONENT),
                createPropertyValueStatementMethodBrowseName, methAddStatementAtr, &createPropertyValueStatement,
                (void*) server, 9, inArgs1, 1, outArgs, &newNodeId);

    /* start server */
    UA_StatusCode retval = UA_Server_run(server, &running); //UA_blocks until running=false

    /* ctrl-c received -> clean up */
    UA_Server_delete(server);
    nl.deleteMembers(&nl);
    return (int) retval;
}
