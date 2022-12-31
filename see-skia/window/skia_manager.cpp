//
// Created by Xinto on 30.12.2022.
//

#include "skia_manager.h"

namespace see::skia::window
{

void skia_manager::init_context(GrDirectContext* context)
{
    gr_context.reset(context);
}

void skia_manager::init_surface(GrBackendRenderTarget& renderTarget)
{
    SkColorType skColorType = kRGBA_8888_SkColorType;
    SkSurface* p_sksurface = SkSurface::MakeFromBackendRenderTarget(
        gr_context.get(),
        renderTarget,
        kBottomLeft_GrSurfaceOrigin,
        skColorType,
        nullptr, nullptr).release();
    sk_surface.reset(p_sksurface);
}

void skia_manager::init_canvas()
{
    canvas = std::make_unique<see::skia::graphics::skia_canvas>(*(sk_surface->getCanvas()));
}

}