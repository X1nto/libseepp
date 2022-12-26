cmake_minimum_required(VERSION 3.24)
project(see-skia)

set(CMAKE_CXX_STANDARD 20)

set(see_skia_graphics_src
        graphics/skia_canvas.h graphics/skia_canvas.cpp
        graphics/skia_color.h graphics/skia_color.cpp window/skia_glfw_window.cpp window/skia_glfw_window.h)

add_library(see_skia ${see_skia_graphics_src})
target_link_libraries(see_skia PUBLIC see)
target_include_directories(see_skia PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SKIA_LIBS REQUIRED IMPORTED_TARGET skia)
target_link_libraries(see_skia PUBLIC PkgConfig::SKIA_LIBS)
target_include_directories(see_skia PUBLIC PkgConfig::SKIA_LIBS_INCLUDE_DIRS)
