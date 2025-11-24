cmake_minimum_required(VERSION 4.0)
project(Projekt_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)

add_executable(Projekt_3
        .idea/.gitignore
        .idea/workspace.xml
        3.cpp
        std_lib_inc.h)
