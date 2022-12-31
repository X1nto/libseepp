cmake_minimum_required(VERSION 3.24)
project(see-skia)

set(CMAKE_CXX_STANDARD 20)

set(see_skia_graphics_src
        graphics/skia_canvas.h graphics/skia_canvas.cpp
        graphics/skia_color.h graphics/skia_color.cpp)

set(see_skia_windowing_src
        windowing/skia_glfw_window.h windowing/skia_glfw_window.cpp
        windowing/skia_manager.h windowing/skia_manager.cpp)

set(see_skia_src
        see_skia.h)

add_library(see_skia
        ${see_skia_graphics_src}
        ${see_skia_windowing_src}
        ${see_skia_src})
target_link_libraries(see_skia PUBLIC see see_glfw)
target_include_directories(see_skia PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SKIA_LIBS REQUIRED IMPORTED_TARGET skia)
target_link_libraries(see_skia PUBLIC PkgConfig::SKIA_LIBS)
target_include_directories(see_skia PUBLIC PkgConfig::SKIA_LIBS_INCLUDE_DIRS)
