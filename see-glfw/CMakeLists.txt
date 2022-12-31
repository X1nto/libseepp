cmake_minimum_required(VERSION 3.24)
project(see-glfw)

set(CMAKE_CXX_STANDARD 20)

set(see_glfw_windowing_src
        windowing/glfw_window.h windowing/glfw_window.cpp)

set(see_glfw_src
        see_glfw.h)

add_library(see_glfw
        ${see_glfw_windowing_src}
        ${see_glfw_src})
target_link_libraries(see_glfw PUBLIC see)
target_include_directories(see_glfw PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW_LIBS REQUIRED IMPORTED_TARGET glfw3)
target_link_libraries(see_glfw PUBLIC PkgConfig::GLFW_LIBS)
target_include_directories(see_glfw PUBLIC PkgConfig::GLFW_LIBS_INCLUDE_DIRS)
