cmake_minimum_required(VERSION 4.0)
project(Team)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)

add_executable(Team
        .idea/.gitignore
        .idea/modules.xml
        .idea/Team.iml
        .idea/workspace.xml
        Projekt_3.cpp
        std_lib_inc.h)
