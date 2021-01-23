/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk_surface_DEFINED
#define sk_surface_DEFINED

#include "include/c/sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

// surface

SK_C_API sk_surface_t* sk_surface_new_raster(const sk_imageinfo_t*, size_t rowBytes, const sk_surfaceprops_t*);
SK_C_API sk_surface_t* sk_surface_new_raster_direct(const sk_imageinfo_t*, void* pixels, size_t rowBytes, const sk_surfaceprops_t* props);

SK_C_API sk_surface_t* sk_surface_new_backend_render_target(gr_direct_context_t* context, const gr_backendrendertarget_t* target, gr_surfaceorigin_t origin, sk_colortype_t colorType, sk_colorspace_t* colorspace, const sk_surfaceprops_t* props);

SK_C_API void sk_surface_unref(sk_surface_t*);
SK_C_API sk_canvas_t* sk_surface_get_canvas(sk_surface_t*);
SK_C_API void sk_surface_flush_and_submit(sk_surface_t* csurf, bool syncCPU);

// surface props

SK_C_API sk_surfaceprops_t* sk_surfaceprops_new(uint32_t flags, sk_pixelgeometry_t geometry);
SK_C_API void sk_surfaceprops_delete(sk_surfaceprops_t* props);

SK_C_PLUS_PLUS_END_GUARD

#endif
