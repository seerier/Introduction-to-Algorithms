cmake_minimum_required(VERSION 3.15)

project(Chapter_6 LANGUAGES CXX)

set(CXX_STANDARD 11)
set(CXX_STANDARD_REQUIED true)

set(CORE_SOURCE 
    util.cpp
    )

add_executable(Insertion_Sort insertion_sort.cpp ${CORE_SOURCE})
add_executable(Merge_Sort merge_sort.cpp ${CORE_SOURCE})

add_executable(Heapsort heapsort.cpp ${CORE_SOURCE})