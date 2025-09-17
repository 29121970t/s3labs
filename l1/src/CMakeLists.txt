add_library(matrix STATIC matrix.cc)
add_library(screens STATIC screens.cc)
add_library(cutils ../../lib/consoleUtils.cc)

add_executable(main main.cc)
target_link_libraries(main matrix cutils screens cutils)
if(CMAKE_SYSTEM_NAME STREQUAL Windows)
    target_link_options(main PRIVATE -static)
endif()
