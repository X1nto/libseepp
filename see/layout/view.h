//
// Created by Xinto on 24.12.2022.
//

#ifndef SEE_LAYOUT_VIEW_H
#define SEE_LAYOUT_VIEW_H

#include <memory>
#include <vector>
#include "see/graphics/canvas.h"
#include "see/graphics/position.h"
#include "see/graphics/size.h"

namespace see::layout
{

struct view_size : see::graphics::size
{
    constexpr static float self = -1;
    constexpr static float parent = -2;
};

class layout;

class view
{
protected:
    graphics::size measured_size{};
    graphics::size constrained_size{};
public:
    std::shared_ptr<layout> parent = nullptr;
    view_size size{
        view_size::self,
        view_size::self
    };

    virtual ~view() = default;

    virtual void draw(
        graphics::canvas& canvas,
        const graphics::position& position) const = 0;

    virtual graphics::size measure_size() const = 0;

    virtual graphics::size constrain_size() const;

    virtual void update();

    graphics::size get_measured_size() const;

    graphics::size get_constrained_size() const;
};

using child_t = std::shared_ptr<view>;
using children_t = std::vector<child_t>;

class layout : public view, public std::enable_shared_from_this<layout>
{
public:
    std::shared_ptr<layout> this_parent()
    {
        return shared_from_this();
    }
};

}

#endif //SEE_LAYOUT_VIEW_H
