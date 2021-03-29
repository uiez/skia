/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/c/gr_direct_context.h"

#include "src/c/sk_types_priv.h"

// GrDirectContext

gr_direct_context_t* gr_direct_context_make_gl(const gr_glinterface_t* glInterface) {
    return SK_ONLY_GL(ToGrDirectContext(GrDirectContext::MakeGL(sk_ref_sp(AsGrGLInterface(glInterface))).release()), nullptr);
}

gr_direct_context_t* gr_direct_context_make_metal(const gr_metal_backendcontext_t *ctx) {
    return SK_ONLY_METAL(ToGrDirectContext(GrDirectContext::MakeMetal(AsGrMtlBackendContext(ctx)).release()), nullptr);
}

gr_direct_context_t* gr_direct_context_make_d3d(const gr_d3d_backendcontext_t *ctx) {
    return SK_ONLY_D3D(ToGrDirectContext(GrDirectContext::MakeDirect3D(AsGrD3DBackendContext(ctx)).release()), nullptr);
}

void gr_direct_context_unref(gr_direct_context_t* context) {
    SK_ONLY_GPU(SkSafeUnref(AsGrDirectContext(context)));
}

void gr_direct_context_flush_and_submit(gr_direct_context_t* context, bool syncCPU) {
    SK_ONLY_GPU(AsGrDirectContext(context)->flushAndSubmit(syncCPU));
}

void gr_direct_context_set_resource_cache_limit(gr_direct_context_t* context, size_t maxResourceBytes) {
    SK_ONLY_GPU(AsGrDirectContext(context)->setResourceCacheLimit(maxResourceBytes));
}

void gr_direct_context_dump_memory_statistics(gr_direct_context_t* context, sk_trace_memory_dump_t *dump) {
    SkTraceMemoryDumpWrapper dumper(dump);
    SK_ONLY_GPU(AsGrDirectContext(context)->dumpMemoryStatistics(&dumper));
}

// GrGLInterface

const gr_glinterface_t* gr_glinterface_assemble_interface(void* ctx, gr_gl_get_proc get) {
    return SK_ONLY_GL(ToGrGLInterface(GrGLMakeAssembledInterface(ctx, get).release()), nullptr);
}

const gr_glinterface_t* gr_glinterface_assemble_gl_interface(void* ctx, gr_gl_get_proc get) {
    return SK_ONLY_GL(ToGrGLInterface(GrGLMakeAssembledGLInterface(ctx, get).release()), nullptr);
}

const gr_glinterface_t* gr_glinterface_assemble_gles_interface(void* ctx, gr_gl_get_proc get) {
    return SK_ONLY_GL(ToGrGLInterface(GrGLMakeAssembledGLESInterface(ctx, get).release()), nullptr);
}

void gr_glinterface_unref(const gr_glinterface_t* glInterface) {
    SK_ONLY_GL(SkSafeUnref(AsGrGLInterface(glInterface)));
}

bool gr_glinterface_validate(const gr_glinterface_t* glInterface) {
    return SK_ONLY_GL(AsGrGLInterface(glInterface)->validate(), false);
}

bool gr_glinterface_has_extension(const gr_glinterface_t* glInterface, const char* extension) {
    return SK_ONLY_GL(AsGrGLInterface(glInterface)->hasExtension(extension), false);
}

bool gr_glinterface_remove_extension(gr_glinterface_t* glInterface, const char* extension) {
    return SK_ONLY_GL(AsGrGLInterface(glInterface)->removeExtension(extension), false);
}

// GrBackendRenderTarget

gr_backendrendertarget_t* gr_backendrendertarget_new_gl(int width, int height, int samples, int stencils, const gr_gl_framebufferinfo_t* glInfo) {
    return SK_ONLY_GL(ToGrBackendRenderTarget(new GrBackendRenderTarget(width, height, samples, stencils, *AsGrGLFramebufferInfo(glInfo))), nullptr);
}

gr_backendrendertarget_t* gr_backendrendertarget_new_metal(int width, int height, const gr_metal_textureinfo_t* mtlInfo) {
    return SK_ONLY_METAL(ToGrBackendRenderTarget(new GrBackendRenderTarget(width, height, AsGrMtlTextureInfo(mtlInfo))), nullptr);
}

gr_backendrendertarget_t* gr_backendrendertarget_new_d3d(int width, int height, const gr_d3d_textureresourceinfo_t* d3dInfo) {
    return SK_ONLY_D3D(ToGrBackendRenderTarget(new GrBackendRenderTarget(width, height, AsGrD3DTextureResourceInfo(d3dInfo))), nullptr);
}

void gr_backendrendertarget_delete(gr_backendrendertarget_t* rendertarget) {
    SK_ONLY_GPU(delete AsGrBackendRenderTarget(rendertarget));
}

bool gr_backendrendertarget_is_valid(const gr_backendrendertarget_t* rendertarget) {
    return SK_ONLY_GPU(AsGrBackendRenderTarget(rendertarget)->isValid(), false);
}
