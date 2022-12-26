cmake_minimum_required(VERSION 3.24)
project(see)

set(CMAKE_CXX_STANDARD 20)

set(see_layout_src
        layout/layout.h layout/layout.cpp
        layout/view.h layout/view.cpp)

set(see_graphics_src
        graphics/canvas.h graphics/canvas.cpp
        graphics/color.h graphics/color.cpp
        graphics/position.h graphics/position.cpp
        graphics/size.h graphics/size.cpp)

set(see_foundation_src
        foundation/column.h foundation/column.cpp
        foundation/row.h foundation/row.cpp)

add_library(see ${see_layout_src} ${see_graphics_src} ${see_foundation_src})
target_include_directories(see PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>)