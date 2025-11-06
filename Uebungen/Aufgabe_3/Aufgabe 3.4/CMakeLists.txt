cmake_minimum_required(VERSION 4.0)
project(Aufgabe_3_4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)

add_executable(Aufgabe_3_4
        .idea/workspace.xml
        3.4.cpp
        std_lib_inc.h)
