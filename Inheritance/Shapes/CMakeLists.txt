cmake_minimum_required(VERSION 3.28)
project(Shapes)

set(CMAKE_CXX_STANDARD 17)

add_executable(Shapes
        Constants.cpp
        Circle.h
        Constants.h
        CoordinateSystemCenter.h
        Rectangle.h
        Vector2D.h
        ShapesMain.cpp
        Shape.h
)
