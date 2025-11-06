cmake_minimum_required(VERSION 4.0)
project(Aufgabe_2_5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)

add_executable(Aufgabe_2_5
        .idea/workspace.xml
        "Aufgabe 2.5.cpp"
        std_lib_inc.h)
