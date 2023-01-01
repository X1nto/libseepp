//
// Created by Xinto on 25.12.2022.
//

#ifndef SEE_FOUNDATION_ROW_H
#define SEE_FOUNDATION_ROW_H

#include "see/layout/layout.h"

namespace see::foundation
{
enum class row_alignment
{
    top,
    center,
    bottom
};

class row : public layout::multichild_layout
{
public:
    float spacing = 0;
    row_alignment children_alignment = row_alignment::top;

    graphics::size measure_size() const override;

    std::vector<see::graphics::position> place_children() const override;
};

}

#endif //SEE_FOUNDATION_ROW_H
