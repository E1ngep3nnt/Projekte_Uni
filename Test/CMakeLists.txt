cmake_minimum_required(VERSION 4.0)
project(Test)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)

add_executable(Test
        .idea/.gitignore
        .idea/workspace.xml
        std_lib_inc.h
        Test.cpp)
