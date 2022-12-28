//
// Created by Xinto on 26.12.2022.
//
#include "skia_glfw_window.h"
#include "see-skia/graphics/skia_canvas.h"

#include <iostream>

namespace see::skia::window
{

void skia_glfw_window::run()
{
    window = glfwCreateWindow(size.width, size.height, title.c_str(), nullptr, nullptr);
    if (!window)
    {
        throw std::runtime_error("failed to create the GLFW window");
    }
    glfwMakeContextCurrent(window);
    glfwSetWindowUserPointer(window, this);
    glfwSetWindowSizeCallback(window, on_window_resize);
    glfwSetFramebufferSizeCallback(window, on_framebuffer_resize);
    glfwSetErrorCallback([](int code, const char *c){
        std::cout << "GLFW Error: " << code << ", " << c;
    });

    glfwSwapInterval(1);

    sk_sp<const GrGLInterface> gr_gl_interface = GrGLMakeNativeInterface();
    gr_context = GrDirectContext::MakeGL(gr_gl_interface).release();

    update();

    while (!glfwWindowShouldClose(window))
    {
        render();
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
    glfwTerminate();
}

void skia_glfw_window::update()
{
    init_sksurface(size.width, size.height);
}

void skia_glfw_window::stop()
{
    glfwDestroyWindow(window);
}

void skia_glfw_window::render()
{
    canvas->clear();

    view->update();
    view->draw(*canvas, see::graphics::position {0, 0});

    gr_context->flush();

    glfwSwapBuffers(window);
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
            gr_context,
            renderTarget,
            kBottomLeft_GrSurfaceOrigin,
            skColorType,
            nullptr, nullptr).release();

    canvas = std::make_unique<see::skia::graphics::skia_canvas>(*sk_surface->getCanvas());
}

void skia_glfw_window::on_window_resize(GLFWwindow* window, int width, int height)
{
    auto* glwindow = get_this_ptr(window);
    glwindow->size.width = width;
    glwindow->size.height = height;
    glwindow->init_sksurface(width, height);
}

void skia_glfw_window::on_framebuffer_resize(GLFWwindow* window, int width, int height)
{
    skia_glfw_window* glwindow = get_this_ptr(window);
    glViewport(0, 0, width, height);

    glwindow->view->size.width = static_cast<float>(width);
    glwindow->view->size.height = static_cast<float>(height);

    glwindow->render();
}

skia_glfw_window* skia_glfw_window::get_this_ptr(GLFWwindow* window)
{
    return static_cast<skia_glfw_window*>(glfwGetWindowUserPointer(window));
}

}


