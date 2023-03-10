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

#include "see/windowing/window.h"
#include "see-skia/graphics/skia_canvas.h"
#include "see-glfw/windowing/glfw_window.h"
#include "skia_manager.h"

namespace see::skia::windowing
{

class skia_glfw_window :
    public see::glfw::windowing::glfw_window,
    public see::skia::windowing::skia_manager
{
public:
    void update() override;

    void stop() override;

protected:
    void render() override;
};

}

#endif //SEE_SKIA_WINDOW_SKIA_GLFW_WINDOW_H