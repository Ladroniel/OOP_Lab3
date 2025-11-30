cmake_minimum_required(VERSION 3.16)
project(lab03_oop_figures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BUILD_TESTING "Build tests" ON)

add_library(figures
    src/square.cpp
    src/rectangle.cpp
    src/trapecia.cpp
)
target_include_directories(figures PUBLIC include)

add_executable(lab03 main.cpp)
target_link_libraries(lab03 PRIVATE figures)

if(BUILD_TESTING)
  include(FetchContent)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  )
  FetchContent_MakeAvailable(googletest)
  enable_testing()
  add_executable(figures_tests test_fig/test_figures.cpp)
  target_link_libraries(figures_tests PRIVATE figures gtest_main)
  add_test(NAME figures_tests COMMAND figures_tests)
endif()
