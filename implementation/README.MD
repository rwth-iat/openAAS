# Asset Administration Shell structuring in openAAS
The Asset Administration Shell Object consists of a Header and a Body. The Header provides information about the Shell and the Asset (Asset ID, Type Reference etc). The Body describes the Asset and the Asset FUNCTIONALality.
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
	"AASID": {
		"IDType": "URI",
		"IDSpec": "http://acplt.org/AAS/Motor_M23"
	},
	"AssetID": {
		"IDType": "URI",
		"IDSpec": "http://acplt.org/Assets/Motor_M23"
	},
	"Header": {
		"PropertyValueStatementContainers": [
			{
				"Name": "Config",
				"statements": [
					{
						"Name": "Asset",
						"CarrierID": "",
						"ExpressionLogic": "EQUAL",
						"ExpressionSemantic": "SETTING",
						"PropertyID": {
							"IDType": "URI",
							"IDSpec": "http://openaas.org/properties/assetId"
						},
						"View": "FUNCTIONAL",
						"Visibilty": "PUBLIC",
						"Value": "URI:http://acplt.org/Assets/Motor_M23"
					},
					{
						"Name": "isInstance",
						"CarrierID": "",
						"ExpressionLogic": "EQUAL",
						"ExpressionSemantic": "ASSURANCE",
						"PropertyID": {
							"IDType": "URI",
							"IDSpec": "https://openaas.org/properties/isInstance"
						},
						"View": "FUNCTIONAL",
						"Visibilty": "PUBLIC",
						"Value": true
					},
					{
						"Name": "TypeAASID",
						"CarrierID": "",
						"ExpressionLogic": "EQUAL",
						"ExpressionSemantic": "MEASUREMENT",
						"PropertyID": {
							"IDType": "URI",
							"IDSpec": "https://openaas.org/properties/TypeID"
						},
						"View": "FUNCTIONAL",
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
								"ExpressionLogic": "EQUAL",
								"ExpressionSemantic": "MEASUREMENT",
								"PropertyID": {
									"IDType": 0,
									"IDSpec": ""
								},
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
								"ExpressionLogic": "EQUAL",
								"ExpressionSemantic": "MEASUREMENT",
								"PropertyID": {
									"IDType": 0,
									"IDSpec": ""
								},
								"View": "FUNCTIONAL",
								"Visibilty": "PUBLIC",
								"Value": false
							}
						]
					}
				],
				"Domains": [
					{
						"Name": "Traces",
						"PropertyValueStatementContainers": [
							{
								"Name": "RotationalSpeed",
								"CarrierID": {
									"IDType": "URI",
									"IDSpec": "http://acplt.org/Assets/Motor_M23"
								},
								"ExpressionSemantic": "ASSURANCE",
								"ExpressionLogic": "GREATER_THAN",
								"PropertyID": {
									"IDType": "URI",
									"IDSpec": "http://acplt.org/properties/currentRotationalSpeed"
								},
								"View": "BUSINESS",
								"Visibility": "PRIVATE"
							}
						]
					}
				]
			},
			{
				"Name": "LifeCycle",
				"Version": 0,
				"Revision": 0,
				"ModelID": {
					"IDType": "URI",
					"IDSpec": "http://acplt.org/models/GenericLifeCycleModel"
				}
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
								"CarrierID": "",
								"ExpressionLogic": "GREATER_THAN",
								"ExpressionSemantic": "",
								"PropertyID": "",
								"View": "",
								"Visibilty": "",
								"Value": 51195
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
						"Visibility": "PRIVATE",
						"View": "BUSINESS",
						"ExpressionSemantic": "ASSURANCE"
					}
				]
			}
		]
	}
}
```
