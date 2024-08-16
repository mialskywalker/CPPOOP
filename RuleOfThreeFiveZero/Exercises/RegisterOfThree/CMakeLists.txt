cmake_minimum_required(VERSION 3.28)
project(RegisterOfThree)

set(CMAKE_CXX_STANDARD 17)

add_executable(RegisterOfThree RegisterMain.cpp
        Register.h
        Company.h
        Register.cpp)
