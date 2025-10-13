cmake_minimum_required(VERSION 3.5)

project(l3)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


include_directories(../)
include_directories(../include)
add_executable(l6 src/main.cc)
add_library(scrHandlersL6 STATIC src/screens.cc)
add_library(consoleUtilsL6 ../lib/consoleUtils.cc)
add_library(carriersL6 ../l3/src/carrier.cc ../l3/src/airplane.cc ../l3/src/car.cc ../l3/src/train.cc)

target_link_libraries(l6 scrHandlersL6 carriersL6 consoleUtilsL6 carriersL6)

