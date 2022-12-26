//
// Created by Xinto on 26.12.2022.
//

#ifndef SEE_SKIA_WINDOW_SKIA_GLFW_WINDOW_H
#define SEE_SKIA_WINDOW_SKIA_GLFW_WINDOW_H

#include <glfw/glfw3.h>

#define SK_GL
#include <skia/include/gpu/GrBackendSurface.h>
#include <skia/include/gpu/GrDirectContext.h>
#include <skia/include/gpu/gl/GrGLInterface.h>
#include <skia/include/core/SkCanvas.h>
#include <skia/include/core/SkColorSpace.h>
#include <skia/include/core/SkSurface.h>
#undef SK_GL

#include "see/window/window.h"
#include "see-skia/graphics/skia_canvas.h"

namespace see::skia::window
{

class skia_glfw_window : public see::window::window
{
    GLFWwindow* window = nullptr;
    sk_sp<GrDirectContext> gr_context = nullptr;
    sk_sp<SkSurface> sk_surface = nullptr;

    std::unique_ptr<see::skia::graphics::skia_canvas> canvas;
public:
    skia_glfw_window();
    ~skia_glfw_window() override;

    void run() override;
    void update() override;
    void stop() override;
private:
    void init_sksurface(int width, int height);
    static void on_window_resize(GLFWwindow* window, int width, int height);
};

}

#endif //SEE_SKIA_WINDOW_SKIA_GLFW_WINDOW_H