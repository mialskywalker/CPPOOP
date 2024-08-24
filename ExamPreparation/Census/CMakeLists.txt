cmake_minimum_required(VERSION 3.28)
project(Census)

set(CMAKE_CXX_STANDARD 17)

add_executable(Census CensusMain.cpp
        CityUtils.h)
