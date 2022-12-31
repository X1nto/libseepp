//
// Created by Xinto on 26.12.2022.
//
#include "skia_glfw_window.h"
#include "see-skia/graphics/skia_canvas.h"

namespace see::skia::window
{

void skia_glfw_window::update()
{
    if (!gr_context)
    {
        sk_sp<const GrGLInterface> interface = GrGLMakeNativeInterface();
        GrDirectContext* context = GrDirectContext::MakeGL(interface).release();
        init_context(context);
    }

    GrGLFramebufferInfo framebufferInfo{
        .fFBOID = 0,
        .fFormat = GL_RGBA8
    };
    GrBackendRenderTarget renderTarget(size.width, size.height, 0, 0, framebufferInfo);
    init_surface(renderTarget);
    init_canvas();
}

void skia_glfw_window::render()
{
    if (canvas)
    {
        canvas->clear();

        view->update();
        view->draw(*canvas, see::graphics::position{0, 0});

        gr_context->flush();

        glfw_window::render();
    }
}

void skia_glfw_window::stop()
{
    canvas.reset();
    sk_surface.reset();
    gr_context.reset();
    glfw_window::stop();
}

}


