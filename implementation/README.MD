# Asset Administration Shell structuring in openAAS
The Asset Administration Shell Object consists of a Header and a Body. The Header provides information about the Shell and the Asset (Asset ID, Type Reference etc). The Body describes the Asset and the Asset functionality.
The information is structured as Sub Models or Property Value Statement Containers (previously Lists) within Header and Body.

**Header**

The Header can consist of Sub Models and Property Value Statement Containers (Lists)

**Body**

The Body can consist of Sub Models and Property Value Statement Containers (Lists)

**Sub Model**

A Sub Model can consists of Property Value Statement Containers, structuring objects (domain) and Services.

**Property Value Statement Container**

A Property Value Statement Container consists of a Set of
Property Value Statements and further describing Attributes like (CarrierID, ExpressionLogic, ExpressionSemantic, Visibility and View).

** ID**

Every Id is represented as ISO 29002-5 Identifcator or as URI

** Example **

In this example, you can see an openAAS Asset Administration Shell (ID = http://acplt.org/AAS/Motor_M23) serialized in JSON format. It describes an Asset (Motor, ID = http://acplt.org/AAS/Motor_M23) .
The motor is of the type ID=http://acplt.org/AAS/MotorType
```json
{
	"Name": "Motor_M23",
	"AssetID": {
		"IDType": "URI",
		"IDSpec": "http://acplt.org/Assets/Motor_M23"
	},
	"AASID": {
		"IDType": "URI",
		"IDSpec": "http://acplt.org/AAS/Motor_M23"
	},
	"Header": {
		"Name": "Header",
		"PropertyValueStatementContainers": [
			{
				"Name": "Config",
				"statements": [
					{
						"Name": "Asset",
						"PropertyID": {
							"IDType": "URI",
							"IDSpec": "http://openaas.org/properties/assetId"
						},
						"ExpressionLogic": "EQUAL",
						"ExpressionSemantic": "SETTING",
						"View": "FUNCTION",
						"Visibilty": "PUBLIC",
						"Value": "URI:http://acplt.org/Assets/Motor_M23"
					},
					{
						"Name": "isInstance",
						"PropertyID": {
							"IDType": "URI",
							"IDSpec": "https://openaas.org/properties/isInstance"
						},
						"ExpressionLogic": "EQUAL",
						"ExpressionSemantic": "ASSURANCE",
						"View": "FUNCTION",
						"Visibilty": "PUBLIC",
						"Value": true
					},
					{
						"Name": "TypeAASID",
						"PropertyID": {
							"IDType": "URI",
							"IDSpec": "https://openaas.org/properties/TypeID"
						},
						"ExpressionLogic": "EQUAL",
						"ExpressionSemantic": "SETTING",
						"View": "FUNCTION",
						"Visibilty": "PUBLIC",
						"Value": "URI:http://acplt.org/AAS/MotorType"
					}
				],
				"CarrierID": {
					"IDType": "URI",
					"IDSpec": "http://acplt.org/AAS/Motor_M23"
				}
			}
		]
	},
	"Body": {
		"Name": "Body",
		"SubModels": [
			{
				"Name": "Runtime",
				"Version": 1,
				"Revision": 1,				
        "ModelID": {
        					"IDType": "URI",
        					"IDSpec": "http://acplt.org/models/MotorRuntimeModel"
        },
				"PropertyValueStatementContainers": [
					{
						"Name": "CurrentStates",
						"statements": [
							{
								"Name": "RotationalSpeed",
								"CarrierID": {
									"IDType": 0,
									"IDSpec": ""
								},
								"PropertyID": {
									"IDType": 0,
									"IDSpec": ""
								},
								"ExpressionLogic": "EQUAL",
								"ExpressionSemantic": "MEASUREMENT",
								"View": "FUNCTIONAL",
								"Visibilty": "PUBLIC",
								"Value": 0
							},
							{
								"Name": "Running",
								"CarrierID": {
									"IDType": 0,
									"IDSpec": ""
								},
								"PropertyID": {
									"IDType": 0,
									"IDSpec": ""
								},
								"ExpressionLogic": "EQUAL",
								"ExpressionSemantic": "MEASUREMENT",
								"View": "FUNCTIONAL",
								"Visibilty": "PUBLIC",
								"Value": false
							}
						]
					}
				]
			},
			{
				"Name": "Configuration",
				"Version": 0,
				"Revision": 0,
				"ModelID": {
					"IDType": "URI",
					"IDSpec": "http://acplt.org/models/MotorConfigurationModel"
				},
				"PropertyValueStatementContainers": [
					{
						"Name": "ConfigurationParameters",
						"statements": [
							{
								"Name": "MinRotationSpeed",
								"ExpressionLogic": "GREATER_THAN",
								"Value": 100
							}
						],
						"CarrierID": {
							"IDType": 0,
							"IDSpec": ""
						},
						"PropertyID": {
							"IDType": 0,
							"IDSpec": ""
						},
						"Visibility": "PUBLIC",
						"View": "FUNCTIONAL",
						"ExpressionSemantic": "ASSURANCE"
					}
				]
			}
		]
	}
}
```
