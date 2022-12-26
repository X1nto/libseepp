//
// Created by Xinto on 26.12.2022.
//

#ifndef SEE_FOUNDATION_BOX_H
#define SEE_FOUNDATION_BOX_H

#include "see/layout/layout.h"

enum class box_alignment
{
    top_start,
    top_center,
    top_end,
    center_start,
    center,
    center_end,
    bottom_start,
    bottom_center,
    bottom_end
};

class box : public see::layout::multichild_layout
{
public:
    box_alignment alignment = box_alignment::top_start;

    void draw(see::graphics::canvas& canvas, const see::graphics::position& position) override;

    see::graphics::size measure_size() override;
};


#endif //SEE_FOUNDATION_BOX_H
