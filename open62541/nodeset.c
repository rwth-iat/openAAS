/* WARNING: This is a generated file.
 * Any manual changes will be overwritten.

 */
#include "nodeset.h"
UA_INLINE void nodeset(UA_Server *server) {
UA_Server_addNamespace(server, "http://yourorganisation.org/PropertyModel/Types.xsd");

do {
// Referencing node found and declared as parent: i=29/Enumeration using i=45/HasSubtype
// Node: opcua_node_dataType_t(ns=2;i=23002), 1:IdentificatorEnumType
UA_DataTypeAttributes attr;
UA_DataTypeAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "IdentificatorEnumType");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 23002);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(0, 29);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 45);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "IdentificatorEnumType");
UA_Server_addDataTypeNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , attr, NULL, NULL);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=23002/1:IdentificatorEnumType using i=46/HasProperty
// Node: opcua_node_variable_t(ns=2;i=6002), EnumStrings
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "EnumStrings");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_LocalizedText opcua_node_variable_t_ns_2_i_6002_variant_DataContents[3];
opcua_node_variable_t_ns_2_i_6002_variant_DataContents[0] = UA_LOCALIZEDTEXT_ALLOC("en_US", "ISO29002-5");
opcua_node_variable_t_ns_2_i_6002_variant_DataContents[1] = UA_LOCALIZEDTEXT_ALLOC("en_US", "URI");
opcua_node_variable_t_ns_2_i_6002_variant_DataContents[2] = UA_LOCALIZEDTEXT_ALLOC("en_US", "Proprietary");
UA_Variant_setArray( &attr.value, &opcua_node_variable_t_ns_2_i_6002_variant_DataContents, (UA_Int32) 3, &UA_TYPES[UA_TYPES_LOCALIZEDTEXT]);
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 6002);
UA_NodeId typeDefinition = UA_NODEID_NULL;
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 23002);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 46);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(0, "EnumStrings");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6002), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6002), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 68), true);
} while(0);

do {
// Referencing node found and declared as parent: i=29/Enumeration using i=45/HasSubtype
// Node: opcua_node_dataType_t(ns=2;i=23003), 1:RelationalExpressionType
UA_DataTypeAttributes attr;
UA_DataTypeAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "RelationalExpressionType");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 23003);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(0, 29);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 45);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "RelationalExpressionType");
UA_Server_addDataTypeNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , attr, NULL, NULL);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=23003/1:RelationalExpressionType using i=46/HasProperty
// Node: opcua_node_variable_t(ns=2;i=26008), EnumStrings
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "EnumStrings");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_LocalizedText opcua_node_variable_t_ns_2_i_26008_variant_DataContents[6];
opcua_node_variable_t_ns_2_i_26008_variant_DataContents[0] = UA_LOCALIZEDTEXT_ALLOC("en_US", "greaterThan");
opcua_node_variable_t_ns_2_i_26008_variant_DataContents[1] = UA_LOCALIZEDTEXT_ALLOC("en_US", "greaterOrEqual");
opcua_node_variable_t_ns_2_i_26008_variant_DataContents[2] = UA_LOCALIZEDTEXT_ALLOC("en_US", "equal");
opcua_node_variable_t_ns_2_i_26008_variant_DataContents[3] = UA_LOCALIZEDTEXT_ALLOC("en_US", "lessOrEqual");
opcua_node_variable_t_ns_2_i_26008_variant_DataContents[4] = UA_LOCALIZEDTEXT_ALLOC("en_US", "lessThan");
opcua_node_variable_t_ns_2_i_26008_variant_DataContents[5] = UA_LOCALIZEDTEXT_ALLOC("en_US", "notEqual");
UA_Variant_setArray( &attr.value, &opcua_node_variable_t_ns_2_i_26008_variant_DataContents, (UA_Int32) 6, &UA_TYPES[UA_TYPES_LOCALIZEDTEXT]);
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 26008);
UA_NodeId typeDefinition = UA_NODEID_NULL;
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 23003);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 46);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(0, "EnumStrings");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 26008), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 26008), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 68), true);
} while(0);

do {
// Referencing node found and declared as parent: i=29/Enumeration using i=45/HasSubtype
// Node: opcua_node_dataType_t(ns=2;i=23004), 1:SemanticExpressionEnumType
UA_DataTypeAttributes attr;
UA_DataTypeAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "SemanticExpressionEnumType");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 23004);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(0, 29);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 45);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "SemanticExpressionEnumType");
UA_Server_addDataTypeNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , attr, NULL, NULL);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=23004/1:SemanticExpressionEnumType using i=46/HasProperty
// Node: opcua_node_variable_t(ns=2;i=6001), EnumStrings
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "EnumStrings");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_LocalizedText opcua_node_variable_t_ns_2_i_6001_variant_DataContents[3];
opcua_node_variable_t_ns_2_i_6001_variant_DataContents[0] = UA_LOCALIZEDTEXT_ALLOC("en_US", "Requirement");
opcua_node_variable_t_ns_2_i_6001_variant_DataContents[1] = UA_LOCALIZEDTEXT_ALLOC("en_US", "Assurance");
opcua_node_variable_t_ns_2_i_6001_variant_DataContents[2] = UA_LOCALIZEDTEXT_ALLOC("en_US", "Measurement");
UA_Variant_setArray( &attr.value, &opcua_node_variable_t_ns_2_i_6001_variant_DataContents, (UA_Int32) 3, &UA_TYPES[UA_TYPES_LOCALIZEDTEXT]);
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 6001);
UA_NodeId typeDefinition = UA_NODEID_NULL;
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 23004);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 46);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(0, "EnumStrings");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6001), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6001), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 68), true);
} while(0);

do {
// Referencing node found and declared as parent: i=35/Organizes using i=45/HasSubtype
// Node: opcua_node_referenceType_t(ns=2;i=24002), 1:HasPropertyRef
UA_ReferenceTypeAttributes attr;
UA_ReferenceTypeAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "HasPropertyRef");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 24002);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(0, 35);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 45);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "HasPropertyRef");
UA_Server_addReferenceTypeNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , attr, NULL, NULL);
} while(0);

do {
// Referencing node found and declared as parent: i=35/Organizes using i=45/HasSubtype
// Node: opcua_node_referenceType_t(ns=2;i=24003), 1:HasPropertyValueStatement
UA_ReferenceTypeAttributes attr;
UA_ReferenceTypeAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "HasPropertyValueStatement");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 24003);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(0, 35);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 45);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "HasPropertyValueStatement");
UA_Server_addReferenceTypeNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , attr, NULL, NULL);
} while(0);

do {
// Referencing node found and declared as parent: i=58/BaseObjectType using i=45/HasSubtype
// Node: opcua_node_objectType_t(ns=2;i=21003), 1:IdentificatorType
UA_ObjectTypeAttributes attr;
UA_ObjectTypeAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "IdentificatorType");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 21003);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(0, 58);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 45);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "IdentificatorType");
UA_Server_addObjectTypeNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , attr, NULL, NULL);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=21003/1:IdentificatorType using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6006), 1:IDspec
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "IDspec");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_String opcua_node_variable_t_ns_2_i_6006_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar( &attr.value, &opcua_node_variable_t_ns_2_i_6006_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
UA_String_deleteMembers(&opcua_node_variable_t_ns_2_i_6006_variant_DataContents);
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 6006);
UA_NodeId typeDefinition = UA_NODEID_NULL;
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 21003);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "IDspec");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6006), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 63), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6006), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=21003/1:IdentificatorType using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6005), 1:IDtype
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "IDtype");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 6005);
UA_NodeId typeDefinition = UA_NODEID_NULL;
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 21003);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "IDtype");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6005), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 63), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6005), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
} while(0);

do {
// Referencing node found and declared as parent: i=58/BaseObjectType using i=45/HasSubtype
// Node: opcua_node_objectType_t(ns=2;i=21002), 1:PropertyType
UA_ObjectTypeAttributes attr;
UA_ObjectTypeAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "PropertyType");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 21002);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(0, 58);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 45);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "PropertyType");
UA_Server_addObjectTypeNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , attr, NULL, NULL);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=21002/1:PropertyType using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=36002), 1:PropertyName
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "PropertyName");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_String opcua_node_variable_t_ns_2_i_36002_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar( &attr.value, &opcua_node_variable_t_ns_2_i_36002_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
UA_String_deleteMembers(&opcua_node_variable_t_ns_2_i_36002_variant_DataContents);
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 36002);
UA_NodeId typeDefinition = UA_NODEID_NULL;
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 21002);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "PropertyName");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 36002), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 63), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 36002), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=21002/1:PropertyType using i=47/HasComponent
// Node: opcua_node_object_t(ns=2;i=5001), 1:SemanticIdentifier
UA_ObjectAttributes attr;
UA_ObjectAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "SemanticIdentifier");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 5001);
UA_NodeId typeDefinition = UA_NODEID_NULL;
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 21002);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "SemanticIdentifier");
UA_Server_addObjectNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 5001), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(2, 21003), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 5001), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=5001/1:SemanticIdentifier using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6003), 1:IDspec
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "IDspec");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_String opcua_node_variable_t_ns_2_i_6003_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar( &attr.value, &opcua_node_variable_t_ns_2_i_6003_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
UA_String_deleteMembers(&opcua_node_variable_t_ns_2_i_6003_variant_DataContents);
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 6003);
UA_NodeId typeDefinition = UA_NODEID_NULL;
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 5001);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "IDspec");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6003), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 63), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6003), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=5001/1:SemanticIdentifier using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6007), 1:IDtype
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "IDtype");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 6007);
UA_NodeId typeDefinition = UA_NODEID_NULL;
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 5001);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "IDtype");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6007), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 63), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6007), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
} while(0);

do {
// Referencing node found and declared as parent: i=58/BaseObjectType using i=45/HasSubtype
// Node: opcua_node_objectType_t(ns=2;i=21004), 1:PropertyValueStatementType
UA_ObjectTypeAttributes attr;
UA_ObjectTypeAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "PropertyValueStatementType");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 21004);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(0, 58);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 45);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "PropertyValueStatementType");
UA_Server_addObjectTypeNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , attr, NULL, NULL);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=21004/1:PropertyValueStatementType using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6012), 1:CreationTime
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "CreationTime");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 6012);
UA_NodeId typeDefinition = UA_NODEID_NULL;
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 21004);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "CreationTime");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6012), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 63), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6012), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=21004/1:PropertyValueStatementType using i=47/HasComponent
// Node: opcua_node_object_t(ns=2;i=5002), 1:Creator
UA_ObjectAttributes attr;
UA_ObjectAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "Creator");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 5002);
UA_NodeId typeDefinition = UA_NODEID_NULL;
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 21004);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "Creator");
UA_Server_addObjectNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 5002), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(2, 21003), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 5002), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=5002/1:Creator using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6013), 1:IDspec
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "IDspec");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_String opcua_node_variable_t_ns_2_i_6013_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar( &attr.value, &opcua_node_variable_t_ns_2_i_6013_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
UA_String_deleteMembers(&opcua_node_variable_t_ns_2_i_6013_variant_DataContents);
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 6013);
UA_NodeId typeDefinition = UA_NODEID_NULL;
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 5002);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "IDspec");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6013), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 63), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6013), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=5002/1:Creator using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6014), 1:IDtype
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "IDtype");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 6014);
UA_NodeId typeDefinition = UA_NODEID_NULL;
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 5002);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "IDtype");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6014), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 63), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6014), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=21004/1:PropertyValueStatementType using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6016), 1:DeviationDown
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "DeviationDown");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 6016);
UA_NodeId typeDefinition = UA_NODEID_NULL;
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 21004);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "DeviationDown");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6016), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 63), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6016), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=21004/1:PropertyValueStatementType using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6015), 1:DeviationUp
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "DeviationUp");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 6015);
UA_NodeId typeDefinition = UA_NODEID_NULL;
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 21004);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "DeviationUp");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6015), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 63), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6015), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=21004/1:PropertyValueStatementType using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6009), 1:RelationalExpression
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "RelationalExpression");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 6009);
UA_NodeId typeDefinition = UA_NODEID_NULL;
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 21004);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "RelationalExpression");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6009), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 63), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6009), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=21004/1:PropertyValueStatementType using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6032), 1:SemanticExpression
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "SemanticExpression");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 6032);
UA_NodeId typeDefinition = UA_NODEID_NULL;
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 21004);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "SemanticExpression");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6032), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 63), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6032), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=21004/1:PropertyValueStatementType using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6010), 1:Unit
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "Unit");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 6010);
UA_NodeId typeDefinition = UA_NODEID_NULL;
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 21004);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "Unit");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6010), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 63), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6010), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=21004/1:PropertyValueStatementType using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6017), 1:ValidFrom
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "ValidFrom");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 6017);
UA_NodeId typeDefinition = UA_NODEID_NULL;
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 21004);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "ValidFrom");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6017), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 63), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6017), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=21004/1:PropertyValueStatementType using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6018), 1:ValidUntil
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "ValidUntil");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 6018);
UA_NodeId typeDefinition = UA_NODEID_NULL;
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 21004);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "ValidUntil");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6018), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 63), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6018), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=21004/1:PropertyValueStatementType using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6011), 1:Value
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "Value");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 6011);
UA_NodeId typeDefinition = UA_NODEID_NULL;
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 21004);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "Value");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6011), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 63), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6011), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
} while(0);
}
