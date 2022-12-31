//
// Created by Xinto on 25.12.2022.
//

#include "column.h"

namespace see::foundation
{

void column::draw(graphics::canvas& canvas, const graphics::position& position) const
{
    graphics::position pos = position;
    for (const see::layout::child_t& child: children)
    {
        const graphics::size measured_child = child->get_measured_size();
        switch(children_alignment)
        {
            case column_alignment::start:
                child->draw(canvas, pos);
                break;
            case column_alignment::center:
            {
                graphics::position center_pos = pos;
                center_pos.x += (measured_size.width - measured_child.width) / 2;
                child->draw(canvas, center_pos);
                break;
            }
            case column_alignment::end:
            {
                graphics::position end_pos = pos;
                end_pos.x += measured_size.width - measured_child.width;
                child->draw(canvas, end_pos);
                break;
            }
        }
        pos.y += measured_child.height + spacing;
    }
}

graphics::size column::measure_size() const
{
    graphics::size size{};

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
