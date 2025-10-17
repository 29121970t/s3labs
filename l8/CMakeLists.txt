cmake_minimum_required(VERSION 3.5)

project(l8)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(../)
include_directories(../include)
add_executable(l8 src/main.cc)
add_library(scrHandlersL8 STATIC src/screens.cc)
add_library(consoleUtilsL8 ../lib/consoleUtils.cc)


target_link_libraries(l8 scrHandlersL8 consoleUtilsL8) 

