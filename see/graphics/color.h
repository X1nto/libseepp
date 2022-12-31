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

inline namespace colors
{

static const constexpr color TRANSPARENT = color(0x00000000);

static const constexpr color BLACK = color(0x000000FF);
static const constexpr color DARK_GRAY = color(0x444444FF);
static const constexpr color GRAY = color(0x888888FF);
static const constexpr color LIGHT_GRAY = color(0xCCCCCCFF);
static const constexpr color WHITE = color(0xFFFFFFFF);

static const constexpr color RED = color(0xFF0000FF);
static const constexpr color ORANGE = color(0xFFA500FF);
static const constexpr color YELLOW = color(0xFFFF00FF);
static const constexpr color GREEN = color(0x00FF00FF);
static const constexpr color CYAN = color(0x00FFFFFF);
static const constexpr color LIGHT_BLUE = color(0xADD8E6FF);
static const constexpr color BLUE = color(0x0000FFFF);
static const constexpr color MAGENTA = color(0xFF00FFFF);
static const constexpr color PURPLE = color(0xA020F0FF);

}

}

#endif //SEE_GRAPHICS_COLOR_H
