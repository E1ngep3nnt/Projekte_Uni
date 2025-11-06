cmake_minimum_required(VERSION 4.0)
project(Aufgabe_1_6_Vorlesungs_Version)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Aufgabe_1_6_Vorlesungs_Version
        .idea/.gitignore
        .idea/workspace.xml
        "Aufgabe 1.6.cpp"
        std_lib_inc.h)
