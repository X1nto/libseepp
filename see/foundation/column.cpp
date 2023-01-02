//
// Created by Xinto on 25.12.2022.
//

#include "column.h"

namespace see::foundation
{

graphics::size column::measure_size() const
{
    graphics::size size{};

    for (int i = 0; i < children.size(); i++)
    {
        const graphics::size& child_size = children[i]->get_compliant_size();

        if (child_size.height != 0)
        {
            if (i != 0)
            {
                size.height += spacing;
            }
            size.height += child_size.height;
        }

        if (child_size.width > size.width)
        {
            size.width = child_size.width;
        }
    }

    return size;
}

std::vector<see::graphics::position> column::place_children() const
{
    graphics::position pos{};
    std::vector<see::graphics::position> positions{};

    for (int i = 0; i < children.size(); i++)
    {
        const see::layout::child_t& child = children[i];
        const graphics::size& child_size = child->get_constrained_size();

        if (i != 0)
        {
            pos.y += spacing;
        }

        switch(children_alignment)
        {
            case column_alignment::start:
                break;
            case column_alignment::center:
                pos.x = (constrained_size.width - child_size.width) / 2;
                break;
            case column_alignment::end:
                pos.x = constrained_size.width - child_size.width;
                break;
        }

        positions.push_back(pos);

        pos.y += child_size.height;
    }

    return positions;
}

}
