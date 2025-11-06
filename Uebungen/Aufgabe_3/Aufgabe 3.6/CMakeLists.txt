cmake_minimum_required(VERSION 4.0)
project(Aufgabe_2_6)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)

add_executable(Aufgabe_2_6
        .idea/.gitignore
        .idea/workspace.xml
        2.6.cpp
        std_lib_inc.h)
