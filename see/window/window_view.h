//
// Created by Xinto on 28.12.2022.
//

#ifndef LIBSEEPP_WINDOW_VIEW_H
#define LIBSEEPP_WINDOW_VIEW_H

#include "see/layout/layout.h"

class window_view : public see::layout::singlechild_layout
{
public:
    see::graphics::size measure_size() const override;
    see::graphics::size constrain_size() const override;
};


#endif //LIBSEEPP_WINDOW_VIEW_H
