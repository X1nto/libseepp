//
// Created by Xinto on 30.12.2022.
//

#include "skia_manager.h"

namespace see::skia::window
{

skia_manager::~skia_manager()
{
    delete sk_surface;
    delete gr_context;
}

void skia_manager::init_context(GrDirectContext* context)
{
    gr_context = context;
}

void skia_manager::init_surface(GrBackendRenderTarget& renderTarget)
{
    SkColorType skColorType = kRGBA_8888_SkColorType;
    sk_surface = SkSurface::MakeFromBackendRenderTarget(
            gr_context,
            renderTarget,
            kBottomLeft_GrSurfaceOrigin,
            skColorType,
            nullptr, nullptr).release();
}

void skia_manager::init_canvas()
{
    canvas = std::make_unique<see::skia::graphics::skia_canvas>(*(sk_surface->getCanvas()));
}

bool skia_manager::context_inited()
{
    return gr_context != nullptr;
}

bool skia_manager::surface_inited()
{
    return sk_surface != nullptr;
}

bool skia_manager::canvas_inited()
{
    return canvas != nullptr;
}

void skia_manager::flush()
{
    gr_context->flush();
}

}