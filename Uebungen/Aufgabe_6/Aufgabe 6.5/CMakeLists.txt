cmake_minimum_required(VERSION 4.0)
project(Aufgabe_6_5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)

add_executable(Aufgabe_6_5
        .idea/.gitignore
        ".idea/Aufgabe 6.5.iml"
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        6.5.cpp
        std_lib_inc.h)
