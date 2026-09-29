include(FetchContent)
FetchContent_Declare(googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip)
FetchContent_MakeAvailable(googletest)

add_executable(greet_test greet_test.cpp)
target_link_libraries(greet_test PRIVATE core GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(greet_test)
