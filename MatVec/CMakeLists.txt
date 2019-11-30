cmake_minimum_required(VERSION 3.15)
project(MatVec)

set(CMAKE_CXX_FLAGS "${CMAKE_SXX_FLAGS} -std=c++17 -Wall -fsanitize=address --coverage")

add_executable(Mat_Vec main.cpp Base.h  Matrix.cpp Matrix.h catch.hpp Vector.h Vector.cpp )