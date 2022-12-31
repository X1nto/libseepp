//
// Created by Xinto on 24.12.2022.
//

#ifndef SEE_GRAPHICS_SIZE_H
#define SEE_GRAPHICS_SIZE_H

namespace see::graphics
{

struct size
{
    float width;
    float height;
};

constexpr size& operator+=(size& lhs, size& rhs)
{
    lhs.width += rhs.width;
    lhs.height += rhs.height;
    return lhs;
}

constexpr size& operator-=(size& lhs, size& rhs)
{
    lhs.width -= rhs.width;
    lhs.height -= rhs.height;
    return lhs;
}

constexpr size operator+(size& lhs, size& rhs)
{
    size new_size = lhs;
    new_size += rhs;
    return new_size;
}

constexpr size operator-(size& lhs, size& rhs)
{
    size new_size = lhs;
    new_size -= rhs;
    return new_size;
}

constexpr bool operator<(const size& lhs, const size& rhs)
{
    if (lhs.width < rhs.width)
        return true;
    if (rhs.width < lhs.width)
        return false;
    return lhs.height < rhs.height;
}

constexpr bool operator>(const size& lhs, const size& rhs)
{
    return rhs < lhs;
}

constexpr bool operator<=(const size& lhs, const size& rhs)
{
    return !(rhs < lhs);
}

constexpr bool operator>=(const size& lhs, const size& rhs)
{
    return !(lhs < rhs);
}

}

#endif //SEE_GRAPHICS_SIZE_H