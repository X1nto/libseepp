//
// Created by Xinto on 30.12.2022.
//

#ifndef SEE_SKIA_SKIA_MANAGER_H
#define SEE_SKIA_SKIA_MANAGER_H

#include <memory>

#include <skia/include/gpu/GrDirectContext.h>
#include <skia/include/core/SkCanvas.h>
#include <skia/include/core/SkColorSpace.h>
#include <skia/include/core/SkSurface.h>

#include "see/graphics/canvas.h"
#include "see-skia/graphics/skia_canvas.h"

namespace see::skia::window
{

class skia_manager
{
protected:
    std::unique_ptr<SkSurface> sk_surface;
    std::unique_ptr<GrDirectContext> gr_context;
    std::unique_ptr<see::skia::graphics::skia_canvas> canvas;
protected:
    void init_context(GrDirectContext* context);

    void init_surface(GrBackendRenderTarget& renderTarget);

    void init_canvas();
};

}

#endif //SEE_SKIA_SKIA_MANAGER_H
