cmake_minimum_required(VERSION 2.6)
set (CMAKE_CXX_STANDARD 11)

option(BUILD_TESTS "Build tests" ON)

project(Shop)
enable_testing()
add_subdirectory(src)
if(BUILD_TESTS)
  add_subdirectory(tests)
endif(BUILD_TESTS)
