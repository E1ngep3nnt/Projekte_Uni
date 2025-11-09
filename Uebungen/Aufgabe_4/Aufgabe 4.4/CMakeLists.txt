cmake_minimum_required(VERSION 4.0)
project(Aufgabe_4_4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)

add_executable(Aufgabe_4_4
        .idea/.gitignore
        ".idea/Aufgabe 4.4.iml"
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        4.4.cpp)
