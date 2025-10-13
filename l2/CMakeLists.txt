cmake_minimum_required(VERSION 3.5)

project(l2)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(../)
include_directories(../include)

add_executable(l2 src/main.cc)
add_library(strL2 STATIC src/string.cc)
add_library(scrHandlersL2 STATIC src/screens.cc)
add_library(consoleUtilsL2 ../lib/consoleUtils.cc)

target_link_libraries(l2 strL2 scrHandlersL2 consoleUtilsL2 )

