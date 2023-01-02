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
    constrained_size = constrain_size();
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

graphics::size view::constrain_size() const
{
    graphics::size constr_size = get_compliant_size();

    if (parent)
    {
        const graphics::size& parent_measured_size = parent->get_compliant_size();

        if (size.width == view_size::parent)
            constr_size.width = parent_measured_size.width;
        if (size.height == view_size::parent)
            constr_size.height = parent_measured_size.height;
    }

    return constr_size;
}

const graphics::size& view::get_measured_size() const
{
    return measured_size;
}

const graphics::size& view::get_constrained_size() const
{
    return constrained_size;
}

const graphics::size& view::get_compliant_size() const
{
    return compliant_size;
}


}
