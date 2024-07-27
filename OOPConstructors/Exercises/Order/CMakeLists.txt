cmake_minimum_required(VERSION 3.28)
project(Order)

set(CMAKE_CXX_STANDARD 17)

add_executable(Order OrderMain.cpp
        OrderedInserter.h
)
