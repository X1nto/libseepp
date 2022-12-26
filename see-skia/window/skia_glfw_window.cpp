//
// Created by Xinto on 26.12.2022.
//
#include "skia_glfw_window.h"
#include "see-skia/graphics/skia_canvas.h"

namespace see::skia::window
{

void skia_glfw_window::run()
{
    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!window)
    {
        throw std::runtime_error("failed to create the GLFW window");
    }
    glfwMakeContextCurrent(window);
    glfwSetWindowUserPointer(window, this);
    glfwSetWindowSizeCallback(window, on_window_resize);
    glfwSwapInterval(1);

    sk_sp<const GrGLInterface> gr_gl_interface = GrGLMakeNativeInterface();
    gr_context = GrDirectContext::MakeGL(gr_gl_interface);

    update();

    while (!glfwWindowShouldClose(window))
    {
        canvas->clear();

        view->update();
        view->draw(*canvas, see::graphics::position {0, 0});

        gr_context->flush();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

skia_glfw_window::skia_glfw_window()
{
    if (!glfwInit())
    {
        throw std::runtime_error("failed to initialize GLFW");
    }
}

skia_glfw_window::~skia_glfw_window()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

void skia_glfw_window::update()
{
    init_sksurface(width, height);
}

void skia_glfw_window::stop()
{
    glfwDestroyWindow(window);
}

void skia_glfw_window::on_window_resize(GLFWwindow* window, int width, int height)
{
    auto* glwindow = static_cast<skia_glfw_window*>(glfwGetWindowUserPointer(window));
    glwindow->width = width;
    glwindow->height = height;
    glwindow->init_sksurface(width, height);
}

void skia_glfw_window::init_sksurface(int width, int height)
{
    GrGLFramebufferInfo framebufferInfo {
        .fFBOID = 0,
        .fFormat = GL_RGBA8
    };
    SkColorType skColorType = kRGBA_8888_SkColorType;
    GrBackendRenderTarget renderTarget(width, height, 0, 0, framebufferInfo);
    sk_surface = SkSurface::MakeFromBackendRenderTarget(
            gr_context.get(),
            renderTarget,
            kBottomLeft_GrSurfaceOrigin,
            skColorType,
            nullptr, nullptr);

    canvas = std::make_unique<see::skia::graphics::skia_canvas>(*sk_surface->getCanvas());
}

}


