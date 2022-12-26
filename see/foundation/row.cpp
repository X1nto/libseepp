//
// Created by Xinto on 25.12.2022.
//

#include "row.h"

namespace see::foundation
{

void row::draw(graphics::canvas& canvas, const graphics::position& position)
{
    graphics::position pos = position;
    for (const layout::child_t& child : children)
    {
        const graphics::size measured = child->measured_size();
        child->draw(canvas, pos);
        pos.x += measured.width + spacing;
    }
}

graphics::size row::measure_size()
{
    graphics::size largest {};

    for (const layout::child_t& child : children)
    {
        const graphics::size measured = child->measured_size();
        if (measured.width > largest.width)
        {
            largest.width = measured.width;
        }
        if (measured.height > largest.height)
        {
            largest.height = measured.height;
        }
    }

    return largest;
}

}
