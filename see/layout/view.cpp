//
// Created by Xinto on 24.12.2022.
//

#include "view.h"

namespace see::layout
{

void view::update()
{
    measured_size = measure_size();
    compliant_size = comply_size();
}

const graphics::size& view::get_measured_size() const
{
    return measured_size;
}

graphics::size view::make_constrained_size() const
{
    graphics::size constrained_size = get_compliant_size();

    if (parent)
    {
        const graphics::size& parent_measured_size = parent->get_measured_size();

        if (size.width == view_size::parent)
            constrained_size.width = parent_measured_size.width;
        if (size.height == view_size::parent)
            constrained_size.height = parent_measured_size.height;
    }

    return constrained_size;
}

const graphics::size& view::get_compliant_size() const
{
    return compliant_size;
}

graphics::size view::comply_size() const
{
    graphics::size compl_size = size;

    if (size.width == view_size::self)
        compl_size.width = measured_size.width;
    if (size.height == view_size::self)
        compl_size.height = measured_size.height;

    return compl_size;
}


}
