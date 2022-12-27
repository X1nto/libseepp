//
// Created by Xinto on 25.12.2022.
//

#include "see/layout/view.h"
#include "see/foundation/column.h"
#include "see/foundation/row.h"
#include "see-skia/window/skia_glfw_window.h"
#include <memory>

class rect_view : public see::layout::view
{
    const see::graphics::color& _color;
public:
    explicit rect_view(const see::graphics::color& color) : _color(color) {};
    void draw(see::graphics::canvas &canvas, const see::graphics::position &position) override
    {
        canvas.draw_rect(position, size, _color);
    }

    see::graphics::size measure_size() override
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
    window.width = 960;
    window.height = 480;
    window.title = "Skia See";

    auto col = std::make_shared<see::foundation::column>();
    col->spacing = 10;
    auto row = std::make_shared<see::foundation::row>();
    row->spacing = 10;

    window.view = col;

    auto red = std::make_shared<rect_view>(see::graphics::color::RED);
    auto green = std::make_shared<rect_view>(see::graphics::color::GREEN);
    auto blue = std::make_shared<rect_view>(see::graphics::color::BLUE);

    (*row) << red << green << blue;
    for (int i = 0; i < 5; i++)
    {
        col->push_child(row);
    }

    window.run();
    return 0;
}