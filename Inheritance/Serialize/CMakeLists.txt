cmake_minimum_required(VERSION 3.28)
project(Serialize)

set(CMAKE_CXX_STANDARD 17)

add_executable(Serialize SerializeMain.cpp
        Serialize.h)
