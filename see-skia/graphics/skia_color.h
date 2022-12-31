//
// Created by Xinto on 25.12.2022.
//

#ifndef SEE_SKIA_GRAPHICS_COLOR_H
#define SEE_SKIA_GRAPHICS_COLOR_H

#include "skia/include/core/SkColor.h"

#include "see/graphics/color.h"

namespace see::skia::graphics
{

constexpr SkColor skia_color(const see::graphics::color& color)
{
    return ((color.alpha() & 0xFF) << 24) +
           ((color.red() & 0xFF) << 16) +
           ((color.green() & 0xFF) << 8) +
           (color.blue() & 0xFF);
}

}

#endif //SEE_SKIA_GRAPHICS_COLOR_H
