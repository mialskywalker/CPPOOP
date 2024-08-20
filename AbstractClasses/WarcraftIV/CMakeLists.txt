cmake_minimum_required(VERSION 3.28)
project(WarcraftIV)

set(CMAKE_CXX_STANDARD 17)

add_executable(WarcraftIV main.cpp
        Archmage.cpp
        DeathKnight.cpp
        DrawRanger.cpp)
