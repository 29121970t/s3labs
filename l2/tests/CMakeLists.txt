include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.17.0
        GIT_SHALLOW TRUE
        GIT_PROGRESS TRUE)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(
  uTest
  uTest.cc
)
target_link_libraries(
  uTest
  GTest::gtest_main
  str
)

include(GoogleTest)
gtest_discover_tests(uTest)
