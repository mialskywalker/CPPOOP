cmake_minimum_required(VERSION 3.28)
project(Tree)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tree TreeMain.cpp
        ByteContainer.h
        File.h
        Directory.h
        TreeView.h)
