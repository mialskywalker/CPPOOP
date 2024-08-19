cmake_minimum_required(VERSION 3.28)
project(SortPointers)

set(CMAKE_CXX_STANDARD 17)

add_executable(SortPointers SortPointersMain.cpp
        Company.h
        SortBy.h)
