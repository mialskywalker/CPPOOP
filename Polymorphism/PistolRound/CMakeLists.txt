cmake_minimum_required(VERSION 3.28)
project(PistolRound)

set(CMAKE_CXX_STANDARD 17)

add_executable(PistolRound main.cpp
        Player.cpp
        DesertEagle.cpp
        Glock.cpp)
