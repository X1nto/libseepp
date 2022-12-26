//
// Created by Xinto on 25.12.2022.
//

#include "column.h"

namespace see::foundation
{

void column::draw(graphics::canvas& canvas, const graphics::position& position)
{
    graphics::position pos = position;
    for (const layout::child_t& child : children)
    {
        const graphics::size measured = child->measured_size();
        child->draw(canvas, pos);
        pos.y += measured.height + spacing;
    }
}

graphics::size column::measure_size()
{
    graphics::size size {};

    for (int i = 0; i < children.size(); i++)
    {
        const graphics::size measured = children[i]->measured_size();
        size.height += measured.height;
        if (measured.width > size.width)
        {
            size.width = measured.width;
        }

        if (i != children.size() - 1)
        {
            size.height += spacing;
        }
    }

    return size;
}

}
