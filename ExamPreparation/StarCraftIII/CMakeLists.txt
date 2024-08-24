cmake_minimum_required(VERSION 3.28)
project(StarCraftIII)

set(CMAKE_CXX_STANDARD 17)

add_executable(StarCraftIII main.cpp
        AirShip.cpp
        BattleField.cpp
        others.cpp
        Viking.cpp
        Phoenix.cpp
        TerranAirShip.cpp
        ProtossAirShip.cpp
        others.h
        BattleCruiser.cpp
        Carrier.cpp)
