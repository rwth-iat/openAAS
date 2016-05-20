/* WARNING: This is a generated file.
 * Any manual changes will be overwritten.

 */
#ifndef NODESET_H_
#define NODESET_H_
#ifdef UA_NO_AMALGAMATION
#include "server/ua_server_internal.h"
#include "server/ua_nodes.h"
#include "ua_util.h"
#include "ua_types.h"
#include "ua_types_encoding_binary.h"
#include "ua_types_generated_encoding_binary.h"
#include "ua_transport_generated_encoding_binary.h"
#else
#include "open62541.h"
#define NULL ((void *)0)
#endif
#define UA_NS2ID_IDENTIFICATORENUMTYPE 23002
#define UA_NS2ID_RELATIONALEXPRESSIONTYPE 23003
#define UA_NS2ID_SEMANTICEXPRESSIONENUMTYPE 23004
#define UA_NS2ID_HASPROPERTYREF 24002
#define UA_NS2ID_HASPROPERTYVALUESTATEMENT 24003
#define UA_NS2ID_IDENTIFICATORTYPE 21003
#define UA_NS2ID_PROPERTYTYPE 21002
#define UA_NS2ID_PROPERTYVALUESTATEMENTTYPE 21004
extern void nodeset(UA_Server *server);

#endif /* NODESET_H_ */
