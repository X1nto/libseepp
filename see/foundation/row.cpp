//
// Created by Xinto on 25.12.2022.
//

#include "row.h"

namespace see::foundation
{

void row::draw(graphics::canvas& canvas, const graphics::position& position) const
{
    graphics::position pos = position;
    for (const see::layout::child_t& child: children)
    {
        const graphics::size measured = child->get_measured_size();
        child->draw(canvas, pos);
        pos.x += measured.width + spacing;
    }
}

graphics::size row::measure_size() const
{
    graphics::size largest{};

    for (int i = 0; i < children.size(); i++)
    {
        const graphics::size measured = children[i]->get_measured_size();
        largest.width += measured.width;
        if (measured.height > largest.height)
        {
            largest.height = measured.height;
        }

        if (i != children.size() - 1)
        {
            largest.width += spacing;
        }
    }

    return largest;
}

}
