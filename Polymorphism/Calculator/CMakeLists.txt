cmake_minimum_required(VERSION 3.28)
project(Calculator)

set(CMAKE_CXX_STANDARD 17)

add_executable(Calculator CalculatorMain.cpp
        Extensions.h)
