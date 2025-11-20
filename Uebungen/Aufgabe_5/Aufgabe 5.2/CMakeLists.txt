cmake_minimum_required(VERSION 4.0)
project(Aufgabe_5_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)

add_executable(Aufgabe_5_2
        .idea/.gitignore
        ".idea/Aufgabe 5.2.iml"
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        5.2.cpp
        std_lib_inc.h)
