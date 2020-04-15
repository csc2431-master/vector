cmake_minimum_required(VERSION 3.10)
project(vector)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(vector
        CMakeLists.txt
        README.md
        unit-test.cpp
        vector.cpp
        vector.h)
