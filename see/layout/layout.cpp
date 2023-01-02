//
// Created by Xinto on 28.12.2022.
//

#include "layout.h"

namespace see::layout
{

void singlechild_layout::draw(graphics::canvas& canvas, const graphics::position& position) const
{
    child->draw(canvas, position);
}

void singlechild_layout::update()
{
    child->update();
    child->parent = this_parent();
}

void multichild_layout::draw(graphics::canvas& canvas, const graphics::position& position) const
{
    for (int i = 0; i < children.size(); i++)
    {
        const child_t& child = children[i];
        const see::graphics::position& child_pos = children_placement[i];

        child->draw(canvas, position + child_pos);
    }
}

void multichild_layout::update()
{
    for (const child_t& child : children)
    {
        child->parent = this_parent();
        child->update();
    }
    view::update();
    children_placement = place_children();
}

const std::vector<see::graphics::position>& multichild_layout::get_children_placement() const
{
    return children_placement;
}


}
