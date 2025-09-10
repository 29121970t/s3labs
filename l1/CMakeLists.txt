cmake_minimum_required(VERSION 3.5)

project(l1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)


enable_testing()

add_subdirectory(src)
include_directories(src)
add_subdirectory(tests)
