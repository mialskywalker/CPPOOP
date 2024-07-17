cmake_minimum_required(VERSION 3.28)
project(Resources)

set(CMAKE_CXX_STANDARD 17)

add_executable(Resources ResourcesMain.cpp
        ResourceType.h
        Resource.h)
