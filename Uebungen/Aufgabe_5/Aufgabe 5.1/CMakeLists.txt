cmake_minimum_required(VERSION 4.0)
project(Aufgabe_5_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)

add_executable(Aufgabe_5_1
        .idea/.gitignore
        .idea/workspace.xml
        5.1.cpp
        std_lib_inc.h)
