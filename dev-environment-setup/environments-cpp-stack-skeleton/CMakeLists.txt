cmake_minimum_required(VERSION 3.20)
project(hello LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(SANITIZE "Enable ASan and UBSan" OFF)
add_compile_options(-Wall -Wextra -Wpedantic -Wconversion -Wshadow)
if(SANITIZE)
  add_compile_options(-fsanitize=address,undefined -fno-omit-frame-pointer)
  add_link_options(-fsanitize=address,undefined)
endif()

add_library(core src/greet.cpp)
target_include_directories(core PUBLIC include)

add_executable(hello src/main.cpp)
target_link_libraries(hello PRIVATE core)

enable_testing()
add_subdirectory(tests)
