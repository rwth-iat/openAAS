
cmake_minimum_required (VERSION 2.6)
project (server_properties)
    add_definitions(-std=c99 -pipe -Wall -Wextra -Werror -Wformat -Wno-unused-parameter
                    -Wno-unused-function -Wno-unused-label -Wpointer-arith -Wreturn-type #-Wsign-compare
                    -Wmultichar -Wstrict-overflow -Wcast-qual -Wmissing-prototypes -Wstrict-prototypes
                    -Winit-self -Wuninitialized -Wformat-security -Wformat-nonliteral
                    -Wno-unused-result -Wno-sign-compare -g)

include_directories(open62541)
add_executable(server_properties examples/server_properties.c open62541/open62541.c open62541/nodeset.c)

