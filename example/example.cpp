//
// Created by Xinto on 25.12.2022.
//

#include "see/see.h"
#include "see-skia/see_skia.h"
#include <memory>

class rect_view : public see::layout::view
{
    const see::graphics::color& _color;
public:
    explicit rect_view(const see::graphics::color& color) : _color(color)
    {};

    void draw(see::graphics::canvas& canvas,
              const see::graphics::position& position) const override
    {
        canvas.draw_rect(position, make_constrained_size(), _color);
    }

    see::graphics::size measure_size() const override
    {
        return {
            .width = 100,
            .height = 50,
        };
    }
};

struct color_item
{
    std::string label;
    see::graphics::color color;
};

int main()
{
    see::skia::windowing::skia_glfw_window window;
    window.size = {
        .width = 960,
        .height = 480,
    };
    window.title = "Skia See";

    auto main_col = std::make_shared<see::foundation::column>();
    main_col->spacing = 20;

    window.view->child = main_col;

    const std::vector<color_item> color_items{
        color_item{
            .label = "Red",
            .color = see::graphics::colors::RED,
        },
        color_item{
            .label = "Green",
            .color = see::graphics::colors::GREEN,
        },
        color_item{
            .label = "Blue",
            .color = see::graphics::colors::BLUE,
        }
    };

    auto rgb_boxes_row = std::make_shared<see::foundation::row>();
    rgb_boxes_row->spacing = 10;

    for (const color_item& color_item : color_items)
    {
        auto container = std::make_shared<see::foundation::column>();
        container->spacing = 5;
        container->children_alignment = see::foundation::column_alignment::center;

        auto rect = std::make_shared<rect_view>(color_item.color);
        auto label = std::make_shared<see::foundation::text>();
        label->color = color_item.color;
        label->text = color_item.label;
        label->size = 15;

        container << rect << label;

        rgb_boxes_row->push_child(container);
    }

    auto rgb_box = std::make_shared<see::foundation::box>();
    rgb_box->children_alignment = see::foundation::box_alignment::center;

    auto red_rect = std::make_shared<rect_view>(see::graphics::colors::RED);
    red_rect->size = {
        100, 100
    };
    auto green_rect = std::make_shared<rect_view>(see::graphics::colors::GREEN);
    green_rect->size = {
        75, 75
    };
    auto blue_rect = std::make_shared<rect_view>(see::graphics::colors::BLUE);
    blue_rect->size = {
        50, 50
    };

    rgb_box << red_rect << green_rect << blue_rect;

    main_col << rgb_boxes_row << rgb_box;

    window.run();
    window.stop();

    return 0;
}