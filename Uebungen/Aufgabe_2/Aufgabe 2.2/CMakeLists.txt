cmake_minimum_required(VERSION 4.0)
project(Aufgabe_2_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)

add_executable(Aufgabe_2_2
        .idea/workspace.xml
        "Aufgabe 2.2.cpp"
        std_lib_inc.h)
