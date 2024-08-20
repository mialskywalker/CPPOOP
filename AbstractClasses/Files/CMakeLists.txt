cmake_minimum_required(VERSION 3.28)
project(Files)

set(CMAKE_CXX_STANDARD 17)

add_executable(Files FilesMain.cpp
        ByteContainer.h
        File.h
        Directory.h)
