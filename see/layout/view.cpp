//
// Created by Xinto on 24.12.2022.
//

#include "view.h"

void see::layout::view::update()
{
    size = measure_size();
}

see::graphics::size see::layout::view::measured_size()
{
    return size;
}
