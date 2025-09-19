cmake_minimum_required(VERSION 3.5)

project(l1)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/TWin.cmake)
enable_testing()
include_directories(../)
include_directories(../include)

add_library(matrix STATIC src/matrix.cc)
add_library(screens STATIC src/screens.cc)
add_library(cutils ../lib/consoleUtils.cc)

add_executable(main src/main.cc)
target_link_libraries(main matrix cutils screens cutils)
if(CMAKE_SYSTEM_NAME STREQUAL Windows)
    target_link_options(main PRIVATE -static)
endif()
