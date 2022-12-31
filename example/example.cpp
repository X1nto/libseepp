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
        canvas.draw_rect(position, constrained_size, _color);
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
    see::skia::window::skia_glfw_window window;
    window.size = {
        .width = 960,
        .height = 480,
    };
    window.title = "Skia See";

    auto row = std::make_shared<see::foundation::row>();
    row->spacing = 10;

    window.view->child = row;

    const std::vector<color_item> color_items{
        color_item{
            .label = "Red",
            .color = see::graphics::color::RED,
        },
        color_item{
            .label = "Green",
            .color = see::graphics::color::GREEN,
        },
        color_item{
            .label = "Blue",
            .color = see::graphics::color::BLUE,
        }
    };

    for (const color_item& color_item: color_items)
    {
        auto container = std::make_shared<see::foundation::column>();
        container->spacing = 5;

        auto rect = std::make_shared<rect_view>(color_item.color);
        auto label = std::make_shared<see::foundation::text>();
        label->color = color_item.color;
        label->text = color_item.label;
        label->size = 15;

        *container << rect << label;

        row->push_child(container);
    }

    window.run();
    window.stop();

    return 0;
}