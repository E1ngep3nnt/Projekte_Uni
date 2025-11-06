cmake_minimum_required(VERSION 4.0)
project(Projekt_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)

add_executable(Projekt_1
        .idea/.gitignore
        .idea/workspace.xml
        Projekt_1.cpp
        std_lib_inc.h)
