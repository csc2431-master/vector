cmake_minimum_required(VERSION 3.10)
project(vector)

set(CMAKE_CXX_STANDARD 14)

add_executable(vector unit-test.cpp vector.h vector.cpp)