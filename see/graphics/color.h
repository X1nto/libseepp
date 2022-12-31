//
// Created by Xinto on 24.12.2022.
//

#ifndef SEE_GRAPHICS_COLOR_H
#define SEE_GRAPHICS_COLOR_H

#include <cstdint>

namespace see::graphics
{

struct color
{
    uint32_t value;

    static const color RED;
    static const color GREEN;
    static const color BLUE;

    explicit constexpr color(uint32_t colorint) : value(colorint)
    {}

    constexpr color(uint8_t r, uint8_t g, uint8_t b) : color(r, g, b, 255)
    {}

    constexpr color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    {
        value = ((r & 0xFF) << 24) +
                ((g & 0xFF) << 16) +
                ((b & 0xFF) << 8) +
                (a & 0xFF);
    }

    constexpr uint8_t red() const
    {
        return (value >> 24) & 0xFF;
    }

    constexpr uint8_t green() const
    {
        return (value >> 16) & 0xFF;
    }

    constexpr uint8_t blue() const
    {
        return (value >> 8) & 0xFF;
    }

    constexpr uint8_t alpha() const
    {
        return value & 0xFF;
    }
};

}

#endif //SEE_GRAPHICS_COLOR_H
