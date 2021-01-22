/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/core/SkCanvas.h"
#include "include/core/SkSurface.h"

#include "include/c/sk_canvas.h"
#include "include/c/sk_surface.h"

#include "src/c/sk_types_priv.h"

// surface

sk_surface_t* sk_surface_new_raster(const sk_imageinfo_t* cinfo, size_t rowBytes, const sk_surfaceprops_t* props) {
    return ToSurface(SkSurface::MakeRaster(AsImageInfo(cinfo), rowBytes, AsSurfaceProps(props)).release());
}

sk_surface_t* sk_surface_new_raster_direct(const sk_imageinfo_t* cinfo, void* pixels, size_t rowBytes, const sk_surfaceprops_t* props) {
    return ToSurface(SkSurface::MakeRasterDirect(AsImageInfo(cinfo), pixels, rowBytes, AsSurfaceProps(props)).release());
}

void sk_surface_unref(sk_surface_t* csurf) {
    SkSafeUnref(AsSurface(csurf));
}

sk_canvas_t* sk_surface_get_canvas(sk_surface_t* csurf) {
    return ToCanvas(AsSurface(csurf)->getCanvas());
}
void sk_surface_flush_and_submit(sk_surface_t* csurf) {
    AsSurface(csurf)->flushAndSubmit();
}
sk_surface_t* sk_surface_new_backend_render_target(gr_direct_context_t* context, const gr_backendrendertarget_t* target, gr_surfaceorigin_t origin, sk_colortype_t colorType, sk_colorspace_t* colorspace, const sk_surfaceprops_t* props) {
    return ToSurface(SkSurface::MakeFromBackendRenderTarget(AsGrDirectContext(context), *AsGrBackendRenderTarget(target), (GrSurfaceOrigin)origin, (SkColorType)colorType, sk_ref_sp(AsColorSpace(colorspace)), AsSurfaceProps(props)).release());
}

// surface props

sk_surfaceprops_t* sk_surfaceprops_new(uint32_t flags, sk_pixelgeometry_t geometry) {
    return ToSurfaceProps(new SkSurfaceProps(flags, (SkPixelGeometry)geometry));
}

void sk_surfaceprops_delete(sk_surfaceprops_t* props) {
    delete AsSurfaceProps(props);
}
