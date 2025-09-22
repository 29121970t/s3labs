cmake_minimum_required(VERSION 3.5)

project(l3)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/TWin.cmake)
enable_testing()
include_directories(../)
include_directories(../include)
add_executable(main src/main.cc)
add_library(scrHandlers STATIC src/screens.cc)
add_library(consoleUtils ../lib/consoleUtils.cc)
add_library(carriers src/carrier.cc src/airplane.cc src/car.cc src/train.cc)

target_link_libraries(main scrHandlers carriers consoleUtils carriers)
if(CMAKE_SYSTEM_NAME STREQUAL Windows)
    target_link_options(main PRIVATE -static)
endif()
