//
// Created by Xinto on 24.12.2022.
//

#ifndef SEE_CANVAS_H
#define SEE_CANVAS_H

#include "position.h"
#include "size.h"
#include "color.h"

namespace see::graphics
{

class canvas
{
public:
    virtual ~canvas() = default;

    virtual void draw_rect(const position& position, const size& size, const color& color) = 0;
    virtual void draw_oval(const position& position, float x_radius, float y_radius, const color& color) = 0;
    virtual void draw_circle(const position& position, float radius, const color& color) = 0;

    virtual void clear() = 0;
};

}

#endif //SEE_CANVAS_H
