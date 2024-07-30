cmake_minimum_required(VERSION 3.28)
project(Register)

set(CMAKE_CXX_STANDARD 17)

add_executable(Register RegisterMain.cpp
        Register.cpp)
