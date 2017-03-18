cmake_minimum_required(VERSION 3.6)
project(Project_Computer_Programming)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.c
        makefile
        README.md)

add_executable(Project_Computer_Programming ${SOURCE_FILES})