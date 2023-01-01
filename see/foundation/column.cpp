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
        const graphics::size& measured = children[i]->get_measured_size();

        if (i != 0)
        {
            size.height += spacing;
        }
        size.height += measured.height;

        if (measured.width > size.width)
        {
            size.width = measured.width;
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
        const graphics::size& measured_child = child->get_measured_size();

        if (i != 0)
        {
            pos.y += spacing;
        }

        switch(children_alignment)
        {
            case column_alignment::start:
                break;
            case column_alignment::center:
                pos.x = (measured_size.width - measured_child.width) / 2;
                break;
            case column_alignment::end:
                pos.x = measured_size.width - measured_child.width;
                break;
        }

        positions.push_back(pos);

        pos.y += measured_child.height;
    }

    return positions;
}

}
