cmake_minimum_required(VERSION 3.28)
project(IDs)

set(CMAKE_CXX_STANDARD 17)

add_executable(IDs IDsMain.cpp
        Company.cpp
        Company.h
        HasId.h
        HasInfo.h)
