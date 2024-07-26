cmake_minimum_required(VERSION 3.28)
project(Echo)

set(CMAKE_CXX_STANDARD 17)

add_executable(Echo EchoMain.cpp
        Echo.h
        EmailContact.cpp
        ContactManagerUI.cpp)
