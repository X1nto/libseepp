//
// Created by Xinto on 24.12.2022.
//

#include "layout.h"

namespace see::layout
{

void singlechild_layout::update()
{
    child->update();
}

void multichild_layout::update()
{
    for (const child_t& child : children)
    {
        child->update();
    }
}


}
