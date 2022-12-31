//
// Created by Xinto on 28.12.2022.
//

#ifndef SEE_WINDOWING_WINDOW_VIEW_H
#define SEE_WINDOWING_WINDOW_VIEW_H

#include "see/layout/layout.h"

namespace see::windowing
{

class window_view : public see::layout::singlechild_layout
{
public:
    see::graphics::size measure_size() const override;

    see::graphics::size constrain_size() const override;
};


}


#endif //SEE_WINDOWING_WINDOW_VIEW_H
