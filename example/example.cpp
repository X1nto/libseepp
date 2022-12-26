//
// Created by Xinto on 25.12.2022.
//

#include "GLFW/glfw3.h"

#define SK_GL
#include "skia/include/gpu/GrBackendSurface.h"
#include "skia/include/gpu/GrDirectContext.h"
#include "skia/include/gpu/gl/GrGLInterface.h"
#include "skia/include/core/SkCanvas.h"
#include "skia/include/core/SkColorSpace.h"
#include "skia/include/core/SkSurface.h"
#undef SK_GL

#include "see-skia/graphics/skia_canvas.h"
#include "see/foundation/column.h"
#include "see/foundation/row.h"

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
    GLFWwindow* window;

    if (!glfwInit())
    {
        return -1;
    }

    window = glfwCreateWindow(960, 480, "Test", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    auto glInterface = GrGLMakeNativeInterface();
    GrDirectContext* context = GrDirectContext::MakeGL(glInterface).release();
    GrGLFramebufferInfo framebufferInfo
    {
        .fFBOID = 0,
        .fFormat = GL_RGBA8
    };

    SkColorType skColorType = kRGBA_8888_SkColorType;
    GrBackendRenderTarget renderTarget(960, 480, 0, 0, framebufferInfo);
    SkSurface* skSurface = SkSurface::MakeFromBackendRenderTarget(
            context, renderTarget, kBottomLeft_GrSurfaceOrigin, skColorType,
            nullptr,nullptr).release();
    if (!skSurface)
    {
        glfwTerminate();
        return -1;
    }

    glfwSwapInterval(1);
    SkCanvas* skCanvas = skSurface->getCanvas();

    std::unique_ptr<SkCanvas> skCanvas_ptr(skCanvas);
    see::skia::graphics::skia_canvas canvas(skCanvas_ptr);

    see::foundation::row row;
    row.spacing = 10;
    see::foundation::column column;
    column.spacing = 10;
    rect_view bluev = rect_view(see::graphics::color::BLUE);
    rect_view redv = rect_view(see::graphics::color::RED);
    rect_view greenv = rect_view(see::graphics::color::GREEN);

    row << bluev << redv << greenv;
    column << row << row;

    while (!glfwWindowShouldClose(window)) {
        glfwWaitEvents();

        column.update();
        column.draw(canvas, see::graphics::position{0, 0});

        context->flush();

        glfwSwapBuffers(window);
    }

    delete skSurface;
    delete context;

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}