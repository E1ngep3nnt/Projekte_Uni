cmake_minimum_required(VERSION 4.0)
project(Aufgabe_1_7)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)

add_executable(Aufgabe_1_7
        .idea/.gitignore
        .idea/workspace.xml
        "Aufgabe 1.7.cpp"
        std_lib_inc.h)
