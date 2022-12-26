//
// Created by Xinto on 25.12.2022.
//

#ifndef SEE_FOUNDATION_ROW_H
#define SEE_FOUNDATION_ROW_H

#include "see/layout/layout.h"

namespace see::foundation
{

class row : public layout::multichild_layout
{
public:
    float spacing = 0;

    graphics::size measure_size() override;

    void draw(graphics::canvas& canvas, const graphics::position& position) override;
};

}

#endif //SEE_FOUNDATION_ROW_H
