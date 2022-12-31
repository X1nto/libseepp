//
// Created by Xinto on 28.12.2022.
//

#include "window_view.h"

namespace see::windowing
{

see::graphics::size window_view::measure_size() const
{
    return size;
}

see::graphics::size window_view::constrain_size() const
{
    return size;
}

}
