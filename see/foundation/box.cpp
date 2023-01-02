//
// Created by Xinto on 26.12.2022.
//

#include "box.h"

namespace see::foundation
{

see::graphics::size box::measure_size() const
{
    see::graphics::size max_size{};
    for (const see::layout::child_t& child: children)
    {
        const see::graphics::size& child_size = child->get_compliant_size();

        if (child_size.width > max_size.width)
            max_size.width = child_size.width;

        if (child_size.height > max_size.height)
            max_size.height = child_size.height;
    }
    return max_size;
}

std::vector<see::graphics::position> box::place_children() const
{
    see::graphics::position pos{};
    std::vector<see::graphics::position> positions;

    for (const see::layout::child_t& child : children)
    {
        const see::graphics::size& child_size = child->get_constrained_size();

        constexpr float top = 0;
        constexpr float start = 0;
        float center_horizontal = (constrained_size.width - child_size.width) / 2;
        float center_vertical = (constrained_size.height - child_size.height) / 2;
        float end = constrained_size.width - child_size.width;
        float bottom = constrained_size.width - child_size.width;

        switch (children_alignment)
        {
            case box_alignment::top_start:
                pos.x = start;
                pos.y = top;
                break;
            case box_alignment::top_center:
                pos.x = center_horizontal;
                pos.y = top;
                break;
            case box_alignment::top_end:
                pos.x = end;
                pos.y = top;
                break;
            case box_alignment::center_start:
                pos.x = start;
                pos.y = center_vertical;
                break;
            case box_alignment::center:
                pos.x = center_horizontal;
                pos.y = center_vertical;
                break;
            case box_alignment::center_end:
                pos.x = end;
                pos.y = center_vertical;
                break;
            case box_alignment::bottom_start:
                pos.x = start;
                pos.y = bottom;
                break;
            case box_alignment::bottom_center:
                pos.x = center_horizontal;
                pos.y = bottom;
                break;
            case box_alignment::bottom_end:
                pos.x = end;
                pos.y = bottom;
                break;
        }

        positions.push_back(pos);
    }

    return positions;
}

}