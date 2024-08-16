cmake_minimum_required(VERSION 3.28)
project(ArrayOfPointers)

set(CMAKE_CXX_STANDARD 17)

add_executable(ArrayOfPointers ArrayOfPointersMain.cpp
        Company.h
        ArrayOfPointers.h)
