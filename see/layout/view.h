//
// Created by Xinto on 24.12.2022.
//

#ifndef SEE_LAYOUT_VIEW_H
#define SEE_LAYOUT_VIEW_H

#include "see/graphics/canvas.h"
#include "see/graphics/position.h"
#include "see/graphics/size.h"

namespace see::layout
{

class view
{
public:
    virtual ~view() = default;

    virtual void draw(graphics::canvas& canvas, const graphics::position& position) = 0;

    virtual graphics::size measure_size() = 0;

    virtual void update();

    graphics::size measured_size();

protected:
    graphics::size size;
};

}

#endif //SEE_LAYOUT_VIEW_H
