cmake_minimum_required(VERSION 3.28)
project(SeparatingDefinitions)

set(CMAKE_CXX_STANDARD 17)

add_executable(SeparatingDefinitions main.cpp
        Company.h
        Company.cpp)
