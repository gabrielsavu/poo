cmake_minimum_required(VERSION 3.13)
project(poo2)

set(CMAKE_CXX_STANDARD 14)

add_executable(poo2 main.cpp point.cpp point.h object.h obarray.cpp obarray.h complex.cpp complex.h)