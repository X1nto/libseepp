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
        const graphics::size& measured = children[i]->get_compliant_size();

        if (measured.width != 0)
        {
            if (i != 0)
            {
                size.width += spacing;
            }
            size.width += measured.width;
        }

        if (measured.height > size.height)
        {
            size.height = measured.height;
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
        const graphics::size& measured_child = child->get_constrained_size();

        if (i != 0)
        {
            pos.x += spacing;
        }

        switch(children_alignment)
        {
            case row_alignment::top:
                break;
            case row_alignment::center:
                pos.y = (measured_size.height - measured_child.height) / 2;
                break;
            case row_alignment::bottom:
                pos.y = measured_size.height - measured_child.height;
                break;
        }

        positions.push_back(pos);

        pos.x += measured_child.width;
    }

    return positions;
}

}
