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
    explicit rect_view(const see::graphics::color& color) : _color(color) {};

    void draw(
            see::graphics::canvas &canvas,
            const see::graphics::position &position) const override
    {
        canvas.draw_rect(position, constrained_size, _color);
    }

    see::graphics::size measure_size() const override
    {
        return see::graphics::size
        {
            .width = 100,
            .height = 50,
        };
    }
};

int main()
{
    see::skia::window::skia_glfw_window window;
    window.size = {
        .width = 960,
        .height = 480,
    };
    window.title = "Skia See";

    auto col = std::make_shared<see::foundation::column>();
    col->spacing = 10;
    auto row = std::make_shared<see::foundation::row>();
    row->spacing = 10;

    window.view->child = col;

    auto red = std::make_shared<rect_view>(see::graphics::color::RED);
    auto green = std::make_shared<rect_view>(see::graphics::color::GREEN);
    auto blue = std::make_shared<rect_view>(see::graphics::color::BLUE);

    (*row) << red << green << blue;
    for (const auto& item: row->children)
    {
        item->size.width = see::layout::view_size::parent;
    }
    for (int i = 0; i < 5; i++)
    {
        col->push_child(row);
    }

    window.run();
    window.stop();

    return 0;
}