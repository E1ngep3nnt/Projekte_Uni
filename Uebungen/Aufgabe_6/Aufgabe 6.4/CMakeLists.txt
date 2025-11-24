cmake_minimum_required(VERSION 4.0)
project(Aufgabe_6_4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)

add_executable(Aufgabe_6_4
        .idea/.gitignore
        ".idea/Aufgabe 6.4.iml"
        .idea/editor.xml
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        6.4.cpp
        std_lib_inc.h)
