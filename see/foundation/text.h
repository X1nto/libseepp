//
// Created by Xinto on 31.12.2022.
//

#ifndef SEE_FOUNDATION_TEXT_H
#define SEE_FOUNDATION_TEXT_H

#include "see/layout/view.h"

namespace see::foundation
{

class text : public layout::view
{
public:
    std::string text;
    float size = 10;
    see::graphics::color color = graphics::color(0x000000FF);

    void draw(graphics::canvas &canvas, const graphics::position &position) const override;
    graphics::size measure_size() const override;
};

}

#endif //SEE_FOUNDATION_TEXT_H
