# openAAS
Development Repository for open Asset Administration Shell (openAAS) by Chair of Process Control Engineering RWTH Aachen University and ZVEI.

**Quick-start: Using the Demo**

For a simple demo that can be run on Linux, please checkout the [ACPLT/RTE](https://github.com/acplt/rte) and follow the installation instruction. In short:
``
git clone https://github.com/acplt/rte
``

``
cd rte/build/ && tclsh acplt_build.tcl
``

``
cd acplt/servers/MANAGER/ && ./build_database.sh
``

``
./start_server.sh &
``

After Installation and start you can load an example that shows two AAS (i.e., for a motor and its Type).

``
./../../system/sysbin/fb_dbcommands -s localhost:7509/MANAGER -load -f ../../../../addonlibs/administration/FBD/openAAS_Demo_17_10_20.fbd
``

Now, you are able to browse the Server with an OPC UA client. The demo AAS can be found within the OCP UA Server

`` 
/Root/Objects///TechUnits/openAAS/AASFolder/
`` 

**Important Information for openAAS Workshop on 2/21/2017**

Another workshop will take place at the end of Februrary. Therefore, the [ACPLT/RTE](https://github.com/acplt/rte) has been extended with an openAAS library. With that library it is possible to create AAS and its components and make it available for different communication technologies, e.g., OPC UA, ACPLT/KS, ACPLT/KSHTTP (REST).
You can download the ACPLT/RTE repository and get familar with the openAAS library. There have been an update on the model implementations (new data types etc.). The related OPC UA nodeset and a client demo can be found here: [workshop](
https://github.com/acplt/openAAS_workshop)


# What's in
This repository shows the current development state of the administration shell and contains definitions, models, specifications, and prototypes. The specifications are based on previous achievements of ZVEI Workgroups.
For prototype development, we use the model based runtime environment [ACPLT/RTE](https://github.com/acplt/rte) as well as open source [OPC UA stack open62541](https://github.com/open62541/open62541) 
There are several base models that are used to describe the constituent parts of an AAS and the AAS itself.


## Important models:
- Asset Administration Shell [(structure)](https://github.com/acplt/openAAS/blob/master/UML/AAS_Structure.pdf)
- Communication Patterns [Demo (Message-based Interaction) September 2016](https://github.com/acplt/openAAS_PropertyDemo/),  [Model Description](https://github.com/acplt/openAAS/blob/master/Doc/ComBasic.pdf)
- Property model [Demo September 2016](https://github.com/acplt/openAAS_PropertyDemo/),  [Model Description](https://github.com/acplt/openAAS/blob/master/Doc/PropertyMetaModel.pdf)
- Lifecylce model 


## How to contribute
There are different ways to contribute to the openAAS project:
- You can set up a new [Issue]( https://github.com/acplt/openAAS/issues) which allows you to describe your concerns and reference to existing specifications.
- If you would like to make some changes and test around and afterwards offer your changes, you can [Fork]( https://help.github.com/articles/fork-a-repo/) openAAS repository, make you changes and offer them by creating a [Pull Request]( https://help.github.com/articles/creating-a-pull-request/).



