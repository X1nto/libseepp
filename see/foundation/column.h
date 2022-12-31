//
// Created by Xinto on 25.12.2022.
//

#ifndef SEE_FOUNDATION_COLUMN_H
#define SEE_FOUNDATION_COLUMN_H

#include "see/layout/layout.h"

namespace see::foundation
{

enum class column_alignment
{
    start,
    center,
    end
};

class column : public layout::multichild_layout
{
public:
    float spacing = 0;
    column_alignment children_alignment = column_alignment::start;

    graphics::size measure_size() const override;

    void draw(graphics::canvas& canvas, const graphics::position& position) const override;
};

}

#endif //SEE_FOUNDATION_COLUMN_H
