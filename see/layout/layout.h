//
// Created by Xinto on 28.12.2022.
//

#ifndef SEE_LAYOUT_LAYOUT_H
#define SEE_LAYOUT_LAYOUT_H

#include "view.h"

namespace see::layout
{

class singlechild_layout : public layout
{
public:
    child_t child;

    void draw(graphics::canvas& canvas, const graphics::position& position) const override;

    void update() override;
};

class multichild_layout : public layout
{
public:
    children_t children;

    void update() override;

    constexpr void push_child(const child_t& child)
    {
        children.push_back(child);
    };
};

constexpr multichild_layout& operator<<(multichild_layout& layout, const child_t& child)
{
    layout.push_child(child);
    return layout;
}

template<class View>
constexpr std::shared_ptr<View>& operator<<(
    std::shared_ptr<View>& layout_ptr,
    const child_t& child)
{
    *layout_ptr << child;
    return layout_ptr;
}

}


#endif //SEE_LAYOUT_LAYOUT_H
