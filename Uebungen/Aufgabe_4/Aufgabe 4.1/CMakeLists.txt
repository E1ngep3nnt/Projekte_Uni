cmake_minimum_required(VERSION 4.0)
project(Aufgabe_4_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)

add_executable(Aufgabe_4_1
        ".idea/Aufgabe 4.1.iml"
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        4.1.cpp
        std_lib_inc.h)
