cmake_minimum_required(VERSION 3.28)
project(Filters)

set(CMAKE_CXX_STANDARD 17)

add_executable(Filters FiltersMain.cpp
        FilterFactory.h)
