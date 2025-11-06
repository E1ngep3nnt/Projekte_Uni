cmake_minimum_required(VERSION 4.0)
project(Aufgabe_3_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)

add_executable(Aufgabe_3_3
        ".idea/Aufgabe 3.3.iml"
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        3.3.cpp
        std_lib_inc.h)
