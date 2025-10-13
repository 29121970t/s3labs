cmake_minimum_required(VERSION 3.5)

project(l3)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(../)
include_directories(../include)
add_executable(l7 src/main.cc)
add_library(scrHandlersL7 STATIC src/screens.cc)
add_library(consoleUtilsL7 ../lib/consoleUtils.cc)
add_library(strinGL7 ../l2/src/string.cc)
add_library(busService ./src/busService.cc)

target_link_libraries(l7 busService scrHandlersL7 consoleUtilsL7 strinGL7)

