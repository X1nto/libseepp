//
// Created by Xinto on 25.12.2022.
//

#include "see/layout/view.h"
#include "see/foundation/column.h"
#include "see/foundation/row.h"
#include "see-skia/window/skia_glfw_window.h"

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

    see::foundation::column col;
    col.spacing = 10;
    see::foundation::row row;
    row.spacing = 10;

    rect_view red = rect_view(see::graphics::color::RED);
    rect_view green = rect_view(see::graphics::color::GREEN);
    rect_view blue = rect_view(see::graphics::color::BLUE);

    row << red << green << blue;
    col << row << row << row;

    window.view = std::unique_ptr<see::foundation::column>(&col);

    window.run();
    return 0;
}