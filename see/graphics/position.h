//
// Created by Xinto on 24.12.2022.
//

#ifndef LIBSEE_POSITION_H
#define LIBSEE_POSITION_H

namespace see::graphics
{

struct position
{
    float x;
    float y;
};

constexpr position& operator+=(position& lhs, const position& rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    return lhs;
}

constexpr position& operator-=(position& lhs, const position& rhs)
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    return lhs;
}

constexpr position operator+(const position& lhs, const position& rhs)
{
    position new_position = lhs;
    new_position += rhs;
    return new_position;
}

constexpr position operator-(const position& lhs, const position& rhs)
{
    position new_position = lhs;
    new_position -= rhs;
    return new_position;
}

constexpr bool operator<(const position& lhs, const position& rhs)
{
    if (lhs.x < rhs.x)
        return true;
    if (rhs.x < lhs.x)
        return false;
    return lhs.y < rhs.y;
}

constexpr bool operator>(const position& lhs, const position& rhs)
{
    return rhs < lhs;
}

constexpr bool operator<=(const position& lhs, const position& rhs)
{
    return !(rhs < lhs);
}

constexpr bool operator>=(const position& lhs, const position& rhs)
{
    return !(lhs < rhs);
}

}

#endif //LIBSEE_POSITION_H
