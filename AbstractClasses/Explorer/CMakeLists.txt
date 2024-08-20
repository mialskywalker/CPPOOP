cmake_minimum_required(VERSION 3.28)
project(Explorer)

set(CMAKE_CXX_STANDARD 17)

add_executable(Explorer ExplorerMain.cpp
        ByteContainer.h
        File.h
        Directory.h
        TreeView.h
        Explorer.h)
