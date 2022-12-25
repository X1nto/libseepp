//
// Created by Xinto on 24.12.2022.
//

#ifndef SEE_VIEW_H
#define SEE_VIEW_H

#include "../graphics/canvas.h"
#include "../graphics/position.h"
#include "../graphics/size.h"

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

#endif //SEE_VIEW_H
