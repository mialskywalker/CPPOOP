cmake_minimum_required(VERSION 3.28)
project(Ranges)

set(CMAKE_CXX_STANDARD 17)

add_executable(Ranges main.cpp
        Range.h
        Range.cpp)
