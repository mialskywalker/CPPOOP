cmake_minimum_required(VERSION 3.28)
project(CompaniesAgain)

set(CMAKE_CXX_STANDARD 17)

add_executable(CompaniesAgain main.cpp
        Company.h
        Company.cpp
        SuperCompany.h)
