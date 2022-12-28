//
// Created by Xinto on 25.12.2022.
//

#include "column.h"

namespace see::foundation
{

void column::draw(graphics::canvas& canvas, const graphics::position& position) const
{
    graphics::position pos = position;
    for (const see::layout::child_t& child : children)
    {
        const graphics::size measured = child->get_measured_size();
        child->draw(canvas, pos);
        pos.y += measured.height + spacing;
    }
}

graphics::size column::measure_size() const
{
    graphics::size size {};

    for (int i = 0; i < children.size(); i++)
    {
        const graphics::size measured = children[i]->get_measured_size();
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
