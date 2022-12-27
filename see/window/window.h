//
// Created by Xinto on 26.12.2022.
//

#ifndef SEE_WINDOW_WINDOW_H
#define SEE_WINDOW_WINDOW_H

#include "see/layout/view.h"
#include "see/layout/layout.h"

namespace see::window
{

class window
{
public:
    std::string title;
    int width;
    int height;
    see::layout::child_t view;

    virtual ~window() = default;

    virtual void run() = 0;
    virtual void update() = 0;
    virtual void stop() = 0;
protected:
    virtual void render() = 0;
};

}

#endif //SEE_WINDOW_WINDOW_H
