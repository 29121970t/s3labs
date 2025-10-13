cmake_minimum_required(VERSION 3.5)

project(l1)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(../)
include_directories(../include)

add_library(matrix STATIC src/matrix.cc)
add_library(screensL1 STATIC src/screens.cc)
add_library(cutils ../lib/consoleUtils.cc)

add_executable(l1 src/main.cc)
target_link_libraries(l1 matrix cutils screensL1 cutils)

