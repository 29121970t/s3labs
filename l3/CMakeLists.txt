cmake_minimum_required(VERSION 3.5)

project(l3)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


include_directories(../)
include_directories(../include)
add_executable(l3 src/main.cc)
add_library(scrHandlersL3 STATIC src/screens.cc)
add_library(consoleUtilsL3 ../lib/consoleUtils.cc)
add_library(carriers src/carrier.cc src/airplane.cc src/car.cc src/train.cc)

target_link_libraries(l3 scrHandlersL3 carriers consoleUtilsL3 carriers)

