cmake_minimum_required(VERSION 3.28)
project(Duplicates)

set(CMAKE_CXX_STANDARD 17)

add_executable(Duplicates DuplicatesMain.cpp
        RemoveDuplicates.h)
