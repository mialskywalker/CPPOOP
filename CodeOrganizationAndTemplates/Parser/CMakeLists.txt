cmake_minimum_required(VERSION 3.28)
project(Parser)

set(CMAKE_CXX_STANDARD 17)

add_executable(Parser ParserMain.cpp
        Parser.h
        PrintUtils.h)
