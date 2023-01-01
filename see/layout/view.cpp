//
// Created by Xinto on 24.12.2022.
//

#include "view.h"

namespace see::layout
{

//FIXME fix constraint measurement for layouts
graphics::size view::constrain_size() const
{
    const bool is_width_parent = size.width == view_size::parent;
    const bool is_height_parent = size.height == view_size::parent;

    const bool is_width_self = size.width == view_size::self;
    const bool is_height_self = size.height == view_size::self;

    graphics::size size_params{
        .width = size.width,
        .height = size.height
    };
    if ((is_width_parent || is_height_parent) && parent)
    {
        graphics::size parent_size = parent->get_constrained_size();
        if (is_width_parent) size_params.width = parent_size.width;
        if (is_height_parent) size_params.height = parent_size.height;
    }

    if (is_width_self) size_params.width = measured_size.width;
    if (is_height_self) size_params.height = measured_size.height;

    return size_params;
}

void view::update()
{
    measured_size = measure_size();
    constrained_size = constrain_size();
}

const graphics::size& view::get_measured_size() const
{
    return measured_size;
}

const graphics::size& view::get_constrained_size() const
{
    return constrained_size;
}


}
