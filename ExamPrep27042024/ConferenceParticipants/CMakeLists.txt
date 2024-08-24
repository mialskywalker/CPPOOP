cmake_minimum_required(VERSION 3.28)
project(ConferenceParticipants)

set(CMAKE_CXX_STANDARD 17)

add_executable(ConferenceParticipants main.cpp
        SilverEmployee.h
        Sponsor.h
        Solution.h)
