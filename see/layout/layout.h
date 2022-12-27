//
// Created by Xinto on 24.12.2022.
//

#ifndef SEE_LAYOUT_LAYOUT_H
#define SEE_LAYOUT_LAYOUT_H

#include <memory>
#include <vector>
#include "view.h"

namespace see::layout
{

using child_t = std::shared_ptr<view>;
using children_t = std::vector<child_t>;

class singlechild_layout : public view
{
public:
    child_t child;

    void update() override;
};

class multichild_layout : public view
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

}

#endif //SEE_LAYOUT_LAYOUT_H
