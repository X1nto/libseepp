//
// Created by Xinto on 29.12.2022.
//

#include "glfw_window.h"

#include <iostream>
#include <stdexcept>

namespace see::glfw
{

glfw_window::glfw_window()
{
    if (!glfwInit())
    {
        throw std::runtime_error("Failed to initialize GLFW");
    }
    glfwSetErrorCallback([](int code, const char *c){
        std::cout << "GLFW Error: " << code << ", " << c;
    });
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

glfw_window::~glfw_window()
{
    glfwTerminate();
}

void glfw_window::run()
{
    window = glfwCreateWindow(size.width, size.height, title.c_str(), nullptr, nullptr);
    if (!window)
    {
        throw std::runtime_error("Failed to create the GLFW window");
    }

    glfwMakeContextCurrent(window);
    glfwSetWindowUserPointer(window, this);
    glfwSetWindowSizeCallback(window, on_window_resize);
    glfwSetFramebufferSizeCallback(window, on_framebuffer_resize);
    glfwSwapInterval(1);

    update();

    while (!glfwWindowShouldClose(window))
    {
        render();

        glfwPollEvents();
    }
}

void glfw_window::render()
{
    glfwSwapBuffers(window);
}

void glfw_window::stop()
{
    glfwDestroyWindow(window);
}

void glfw_window::on_window_resize(GLFWwindow* window, int width, int height)
{
    glfw_window* glwindow = get_this_ptr(window);

    glwindow->size.width = width;
    glwindow->size.height = height;

    glwindow->update();
}

void glfw_window::on_framebuffer_resize(GLFWwindow* window, int width, int height)
{
    glfw_window* glwindow = get_this_ptr(window);
    glViewport(0, 0, width, height);

    glwindow->view->size.width = static_cast<float>(width);
    glwindow->view->size.height = static_cast<float>(height);

    glwindow->render();
}

glfw_window* glfw_window::get_this_ptr(GLFWwindow* window)
{
    return static_cast<glfw_window*>(glfwGetWindowUserPointer(window));
}

}

