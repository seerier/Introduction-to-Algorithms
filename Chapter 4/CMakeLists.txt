cmake_minimum_required(VERSION 3.15)

project(Chapter_4 LANGUAGES CXX)

set(CXX_STANDARD 11)
set(CXX_STANDARD_REQUIED true)

set(CORE_SOURCE 
    matrix_multiply.cpp 
    util.cpp
    )

add_executable(Brute_force brute_force.cpp ${CORE_SOURCE})
add_executable(Divide_conquer divide_conquer.cpp ${CORE_SOURCE})