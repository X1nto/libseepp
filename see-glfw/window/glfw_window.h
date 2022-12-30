//
// Created by Xinto on 29.12.2022.
//

#ifndef SEE_GLFW_GLFW_WINDOW_H
#define SEE_GLFW_GLFW_WINDOW_H

#include "see/window/window.h"

#include <GLFW/glfw3.h>

namespace see::glfw
{

class glfw_window : public see::window::window
{
    GLFWwindow* window = nullptr;
public:
    glfw_window();
    ~glfw_window() override;

    void run() override;
    void stop() override;
protected:
    void render() override;
private:
    static void on_window_resize(GLFWwindow* window, int width, int height);
    static void on_framebuffer_resize(GLFWwindow* window, int width, int height);
    static glfw_window* get_this_ptr(GLFWwindow* window);
};

}

#endif //SEE_GLFW_GLFW_WINDOW_H
