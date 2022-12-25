cmake_minimum_required(VERSION 3.24)
project(see-example)

set(CMAKE_CXX_STANDARD 20)

add_executable(example example.cpp)
find_package(glfw3 REQUIRED)
target_link_libraries(example PRIVATE see see_skia glfw3)
target_include_directories(example PRIVATE $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>)

