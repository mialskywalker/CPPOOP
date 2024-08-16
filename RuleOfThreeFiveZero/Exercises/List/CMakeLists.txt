cmake_minimum_required(VERSION 3.28)
project(List)

set(CMAKE_CXX_STANDARD 17)

add_executable(List ListMain.cpp
        List.h
        List.cpp)
