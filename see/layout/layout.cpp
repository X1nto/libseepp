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

void multichild_layout::update()
{
    view::update();
    for (const child_t& child : children)
    {
        child->update();
        child->parent = this_parent();
    }
}

}
