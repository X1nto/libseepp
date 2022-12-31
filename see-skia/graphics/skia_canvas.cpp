//
// Created by Xinto on 25.12.2022.
//

#include "skia_canvas.h"
#include "skia_color.h"

#include <skia/include/core/SkTextBlob.h>

namespace see::skia::graphics
{

skia_canvas::skia_canvas(SkCanvas& _canvas) : canvas(_canvas)
{}

void skia_canvas::draw_rect(const see::graphics::position& position,
                            const see::graphics::size& size,
                            const see::graphics::color& color)
{
    const SkRect rect{
        .fLeft = position.x,
        .fTop = position.y,
        .fRight = position.x + size.width,
        .fBottom = position.y + size.height,
    };
    SkPaint paint;
    paint.setColor(skia_color(color));
    canvas.drawRect(rect, paint);
}

void skia_canvas::draw_circle(
    const see::graphics::position& position,
    float radius,
    const see::graphics::color& color)
{
    const SkPoint center{
        .fX = position.x + radius,
        .fY = position.y + radius
    };
    SkPaint paint;
    paint.setColor(skia_color(color));
    canvas.drawCircle(center, radius, paint);
}

void skia_canvas::draw_oval(const see::graphics::position& position,
                            float x_radius, float y_radius,
                            const see::graphics::color& color)
{
    const SkRect oval{
        .fLeft = position.x,
        .fTop = position.y,
        .fRight = position.x + x_radius,
        .fBottom = position.y + y_radius,
    };
    SkPaint paint;
    paint.setColor(skia_color(color));
    canvas.drawOval(oval, paint);
}

void skia_canvas::draw_text(const see::graphics::position& position,
                            const std::string& text,
                            float size,
                            const see::graphics::color& color)
{
    SkFont font;
    font.setSize(size);
    SkPaint paint;
    paint.setColor(skia_color(color));
    canvas.drawSimpleText(
        text.c_str(),
        text.length(),
        SkTextEncoding::kUTF8,
        position.x, position.y + size,
        font,
        paint);
}

void skia_canvas::clear()
{
    canvas.clear(skia_color(see::graphics::color(255, 255, 255)));
}

}