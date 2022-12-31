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
        const graphics::size measured_child = child->get_measured_size();
        switch(children_alignment)
        {
            case row_alignment::top:
                child->draw(canvas, pos);
                break;
            case row_alignment::center:
            {
                graphics::position center_pos = pos;
                center_pos.y += (measured_size.height - measured_child.height) / 2;
                child->draw(canvas, center_pos);
                break;
            }
            case row_alignment::bottom:
            {
                graphics::position end_pos = pos;
                end_pos.y += measured_size.height - measured_child.height;
                child->draw(canvas, end_pos);
                break;
            }
        }
        pos.x += measured_child.width + spacing;
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
