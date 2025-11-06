cmake_minimum_required(VERSION 4.0)
project(Aufgabe_2_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)

add_executable(Aufgabe_2_3
        .idea/.gitignore
        .idea/workspace.xml
        2.3.cpp
        std_lib_inc.h)
