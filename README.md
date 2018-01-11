# openAAS - \*updated\*
*NEW* : [JSON Serialization](https://github.com/acplt/openAAS/implementation) of openAAS Administration Shell

Development Repository for open Asset Administration Shell (openAAS) by Chair of Process Control Engineering RWTH Aachen University and ZVEI.


# What you can find here
This repository shows the current development state of the administration shell and contains models, specifications. The specifications are based on previous achievements of ZVEI Workgroups.
For prototype development, we use the model based runtime environment [ACPLT/RTE](https://github.com/acplt/rte) as well as open source [OPC UA stack open62541](https://github.com/open62541/open62541)
There are several base models that are used to describe the constituent parts of an AAS and the AAS itself.

The implementation of openAAS bases on the specification given by working papers of [ZVEI/ Plattform Industrie 4.0](www.plattform-i40.de/I40/Redaktion/EN/Downloads/Publikation/structure-of-the-administration-shell.pdf?__blob=publicationFile&v=7)

With these specification a simplified model for the Asset Administration Shell is proposed [(structure)](https://github.com/acplt/openAAS/blob/master/concepts/structure/structure.pdf).

Within the [implementation](https://github.com/acplt/openAAS/blob/master/implementation/) folder, you can find the needed OPC UA models to describe an openAAS Asset Administration Shell with your OPC UA Server. Within the folder you also find a basic example of an Asset Administration Shell for a motor serialzed in JSON.

If you just want to have a look at an OPC UA openAAS Asset Administration Shell you can skip to the next section.

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



## How to contribute
There are different ways to contribute to the openAAS project:
- You can set up a new [Issue]( https://github.com/acplt/openAAS/issues) which allows you to describe your concerns and reference to existing specifications.
- If you would like to make some changes and test around and afterwards offer your changes, you can [Fork]( https://help.github.com/articles/fork-a-repo/) openAAS repository, make you changes and offer them by creating a [Pull Request]( https://help.github.com/articles/creating-a-pull-request/).
