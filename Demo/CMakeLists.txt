cmake_minimum_required(VERSION 3.28)
project(Demo)

set(CMAKE_CXX_STANDARD 17)

add_executable(Demo LecturesMain.cpp ResourceType.h
        Resource.h
        Lecture.h)
