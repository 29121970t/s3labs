cmake_minimum_required(VERSION 3.5)

project(l3)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


include_directories(../)
include_directories(../include)
add_executable(l4 src/main.cc)
add_library(scrHandlersL4 STATIC src/screens.cc)
add_library(consoleUtilsL4 ../lib/consoleUtils.cc)
add_library(carriersL4 src/carrier.cc src/wagon.cc src/car.cc src/bicycle.cc)

target_link_libraries(l4 scrHandlersL4 carriersL4 scrHandlersL4 consoleUtilsL4)
