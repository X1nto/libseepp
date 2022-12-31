//
// Created by Xinto on 25.12.2022.
//

#ifndef SEE_SKIA_GRAPHICS_CANVAS_H
#define SEE_SKIA_GRAPHICS_CANVAS_H

#include "skia/include/core/SkCanvas.h"

#include "see/graphics/canvas.h"
#include "see/graphics/color.h"
#include "see/graphics/position.h"

namespace see::skia::graphics
{

class skia_canvas : public see::graphics::canvas
{
    SkCanvas& canvas;
public:
    explicit skia_canvas(SkCanvas& _canvas);
    ~skia_canvas() override = default;

    void draw_rect(
            const see::graphics::position &position,
            const see::graphics::size &size,
            const see::graphics::color &color) override;

    void draw_circle(
            const see::graphics::position &position,
            float radius,
            const see::graphics::color &color) override;

    void draw_oval(
            const see::graphics::position &position,
            float x_radius,
            float y_radius,
            const see::graphics::color &color) override;

    void draw_text(
            const see::graphics::position &position,
            const std::string& text,
            float size,
            const see::graphics::color& color) override;

    void clear() override;
};


}

#endif //SEE_SKIA_GRAPHICS_CANVAS_H
