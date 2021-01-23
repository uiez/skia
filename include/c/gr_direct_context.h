/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef gr_context_DEFINED
#define gr_context_DEFINED

#include "include/c/sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

// GrContext

SK_C_API gr_direct_context_t* gr_direct_context_make_gl(const gr_glinterface_t* glInterface);
SK_C_API gr_direct_context_t* gr_direct_context_make_metal(void* device, void* queue);
SK_C_API gr_direct_context_t* gr_direct_context_make_d3d(const gr_d3d_backendcontext_t *ctx);

SK_C_API void gr_direct_context_unref(gr_direct_context_t* context);
SK_C_API void gr_direct_context_flush_and_submit(gr_direct_context_t* context, bool syncCPU);

// GrGLInterface

SK_C_API const gr_glinterface_t* gr_glinterface_assemble_interface(void* ctx, gr_gl_get_proc get);
SK_C_API const gr_glinterface_t* gr_glinterface_assemble_gl_interface(void* ctx, gr_gl_get_proc get);
SK_C_API const gr_glinterface_t* gr_glinterface_assemble_gles_interface(void* ctx, gr_gl_get_proc get);

SK_C_API void gr_glinterface_unref(const gr_glinterface_t* glInterface);
SK_C_API bool gr_glinterface_validate(const gr_glinterface_t* glInterface);
SK_C_API bool gr_glinterface_has_extension(const gr_glinterface_t* glInterface, const char* extension);
SK_C_API bool gr_glinterface_remove_extension(gr_glinterface_t* glInterface, const char* extension);

// GrBackendRenderTarget

SK_C_API gr_backendrendertarget_t* gr_backendrendertarget_new_gl(int width, int height, int samples, int stencils, const gr_gl_framebufferinfo_t* info);
SK_C_API gr_backendrendertarget_t* gr_backendrendertarget_new_metal(int width, int height, const gr_metal_textureinfo_t* info);
SK_C_API gr_backendrendertarget_t* gr_backendrendertarget_new_d3d(int width, int height, const gr_d3d_textureresourceinfo_t* info);

SK_C_API void gr_backendrendertarget_delete(gr_backendrendertarget_t* rendertarget);
SK_C_API bool gr_backendrendertarget_is_valid(const gr_backendrendertarget_t* rendertarget);

SK_C_PLUS_PLUS_END_GUARD

#endif
