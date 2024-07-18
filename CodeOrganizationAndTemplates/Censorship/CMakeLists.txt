cmake_minimum_required(VERSION 3.28)
project(Censorship)

set(CMAKE_CXX_STANDARD 17)

add_executable(CensorshipMain.cpp
        Article13Filter.cpp
        CensorshipMain.cpp)
