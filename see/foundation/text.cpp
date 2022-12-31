//
// Created by Xinto on 31.12.2022.
//

#include "text.h"

void see::foundation::text::draw(see::graphics::canvas& canvas,
                                 const see::graphics::position& position) const
{
    canvas.draw_text(position, text, size, color);
}

see::graphics::size see::foundation::text::measure_size() const
{
    return {
        .width = (size / 2) * static_cast<float>(text.length()),
        .height = size
    };
}
