//
// Created by Xinto on 25.12.2022.
//

#include "row.h"

namespace see::foundation
{

graphics::size row::measure_size() const
{
    graphics::size size{};

    for (int i = 0; i < children.size(); i++)
    {
        const graphics::size& child_size = children[i]->get_compliant_size();

        if (child_size.width != 0)
        {
            if (i != 0)
            {
                size.width += spacing;
            }
            size.width += child_size.width;
        }

        if (child_size.height > size.height)
        {
            size.height = child_size.height;
        }
    }

    return size;
}

std::vector<see::graphics::position> row::place_children() const
{
    graphics::position pos{};
    std::vector<see::graphics::position> positions{};

    for (int i = 0; i < children.size(); i++)
    {
        const see::layout::child_t& child = children[i];
        const graphics::size& child_size = child->get_constrained_size();

        if (i != 0)
        {
            pos.x += spacing;
        }

        switch(children_alignment)
        {
            case row_alignment::top:
                break;
            case row_alignment::center:
                pos.y = (constrained_size.height - child_size.height) / 2;
                break;
            case row_alignment::bottom:
                pos.y = constrained_size.height - child_size.height;
                break;
        }

        positions.push_back(pos);

        pos.x += child_size.width;
    }

    return positions;
}

}
