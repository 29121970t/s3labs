cmake_minimum_required(VERSION 3.5)

project(l1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")


add_compile_options(-Wall -Wextra -Wpedantic -Werror)
if(CMAKE_SYSTEM_NAME STREQUAL Windows)
  add_link_options(-static)
endif()

enable_testing()
add_subdirectory(tests)


add_subdirectory(src)
include_directories(src)
