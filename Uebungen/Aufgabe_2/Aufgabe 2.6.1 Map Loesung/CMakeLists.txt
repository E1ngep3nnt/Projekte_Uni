cmake_minimum_required(VERSION 4.0)
project(Aufgabe_2_6_1_Map_Loesung)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)

add_executable(Aufgabe_2_6_1_Map_Loesung
        .idea/workspace.xml
        "Aufgabe 2.6.cpp"
        std_lib_inc.h)
