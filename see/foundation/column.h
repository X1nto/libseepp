//
// Created by Xinto on 25.12.2022.
//

#ifndef LIBSEE_COLUMN_H
#define LIBSEE_COLUMN_H

#include "../layout/layout.h"

namespace see::foundation
{

class column : public layout::multichild_layout
{
public:
    float spacing = 0;

    graphics::size measure_size() override;

    void draw(graphics::canvas& canvas, const graphics::position& position) override;
};

}

#endif //LIBSEE_COLUMN_H
