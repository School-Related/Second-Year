cmake_minimum_required(VERSION 3.24)
project(Programs)

set(CMAKE_CXX_STANDARD 14 Debug)

add_executable(Programs
        Matrix_calc.c
        saddle_point.cpp
        sparce_matrix.c
        test.c sets.c)
