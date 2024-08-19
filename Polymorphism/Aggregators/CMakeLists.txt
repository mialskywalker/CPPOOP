cmake_minimum_required(VERSION 3.28)
project(Aggregators)

set(CMAKE_CXX_STANDARD 17)

add_executable(Aggregators AggregatorsMain.cpp
        SumAggregator.h
        AverageAggregator.h
        MinAggregator.h)
