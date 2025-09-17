add_executable(main main.cc)
add_library(str STATIC string.cc)
add_library(scrHandlers STATIC screens.cc)
add_library(consoleUtils ../../lib/consoleUtils.cc)

target_link_libraries(main str scrHandlers consoleUtils)
if(CMAKE_SYSTEM_NAME STREQUAL Windows)
    target_link_options(main PRIVATE -static)
endif()
