cmake_minimum_required(VERSION 3.28)
project(Sorting)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sorting SortingMain.cpp
        Parser.h
        Comparators.h
        PrintUtils.h)
