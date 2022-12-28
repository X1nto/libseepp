//
// Created by Xinto on 24.12.2022.
//

#ifndef SEE_GRAPHICS_SIZE_INT_H
#define SEE_GRAPHICS_SIZE_INT_H

namespace see::graphics
{

struct size_int
{
    int width;
    int height;
};

constexpr size_int &operator+=(size_int &lhs, size_int &rhs)
{
    lhs.width += rhs.width;
    lhs.height += rhs.height;
    return lhs;
}

constexpr size_int &operator-=(size_int &lhs, size_int &rhs)
{
    lhs.width -= rhs.width;
    lhs.height -= rhs.height;
    return lhs;
}

constexpr size_int operator+(size_int &lhs, size_int &rhs)
{
    size_int new_size = lhs;
    new_size += rhs;
    return new_size;
}

constexpr size_int operator-(size_int &lhs, size_int &rhs)
{
    size_int new_size = lhs;
    new_size -= rhs;
    return new_size;
}

constexpr bool operator<(const size_int& lhs, const size_int& rhs)
{
    if (lhs.width < rhs.width)
        return true;
    if (rhs.width < lhs.width)
        return false;
    return lhs.height < rhs.height;
}

constexpr bool operator>(const size_int& lhs, const size_int& rhs)
{
    return rhs < lhs;
}

constexpr bool operator<=(const size_int& lhs, const size_int& rhs)
{
    return !(rhs < lhs);
}

constexpr bool operator>=(const size_int& lhs, const size_int& rhs)
{
    return !(lhs < rhs);
}


}

#endif //SEE_GRAPHICS_SIZE_INT_H