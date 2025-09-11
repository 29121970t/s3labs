cmake_minimum_required(VERSION 3.5)

project(l1)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/TWin.cmake)
enable_testing()

add_subdirectory(src)
include_directories(src)
if(BUILD_TESTS)
    add_subdirectory(tests)
endif()