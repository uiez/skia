/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk_types_priv_DEFINED
#define sk_types_priv_DEFINED

#include "include/c/sk_types.h"
#include "include/core/SkTypes.h" // required to make sure SK_SUPPORT_GPU is defined
#include "include/effects/SkImageFilters.h" // required to make sure SK_SUPPORT_GPU is defined

#define SK_SKIP_ARG__(keep, skip, ...) skip
#define SK_SKIP_ARG_(args) SK_SKIP_ARG__ args
#define SK_SKIP_ARG(...) SK_SKIP_ARG_((__VA_ARGS__, ))

#define SK_FIRST_ARG__(keep, skip, ...) keep
#define SK_FIRST_ARG_(args) SK_FIRST_ARG__ args
#define SK_FIRST_ARG(...) SK_FIRST_ARG_((__VA_ARGS__, ))

#if SK_SUPPORT_GPU
#    include "include/gpu/GrDirectContext.h"
#    include "include/gpu/GrBackendSurface.h"

#    define SK_ONLY_GPU(...) SK_FIRST_ARG(__VA_ARGS__)

#    if SK_GL
#        include "include/gpu/gl/GrGLInterface.h"
#        include "include/gpu/gl/GrGLAssembleInterface.h"
#        define SK_ONLY_GL(...) SK_FIRST_ARG(__VA_ARGS__)
#    else
#        define SK_ONLY_GL(...) SK_SKIP_ARG(__VA_ARGS__)
#    endif
#    if SK_METAL
#        include "include/gpu/mtl/GrMtlTypes.h"
#        define SK_ONLY_METAL(...) SK_FIRST_ARG(__VA_ARGS__)
#    else
#        define SK_ONLY_METAL(...) SK_SKIP_ARG(__VA_ARGS__)
#    endif
#    if SK_DIRECT3D
#        include "include/gpu/d3d/GrD3DTypes.h"
#        include "include/gpu/d3d/GrD3DBackendContext.h"
#        define SK_ONLY_D3D(...) SK_FIRST_ARG(__VA_ARGS__)
#    else
#        define SK_ONLY_D3D(...) SK_SKIP_ARG(__VA_ARGS__)
#    endif
#else // !SK_SUPPORT_GPU
#    define SK_ONLY_GPU(...) SK_SKIP_ARG(__VA_ARGS__)
#    define SK_ONLY_GL(...) SK_SKIP_ARG(__VA_ARGS__)
#    define SK_ONLY_METAL(...) SK_SKIP_ARG(__VA_ARGS__)
#    define SK_ONLY_D3D(...) SK_SKIP_ARG(__VA_ARGS__)
#endif // SK_SUPPORT_GPU


// Define a mapping between a C++ type and the C type.
//
// Usual Values:
//  - C++  |  SkType   |  SkSomeType
//  - C    |  sk_type  |  sk_some_type_t
//  - Map  |  Name     |  ToSomeType / AsSomeType
//
#define DEF_MAP_DECL(SkType, sk_type, Name, Declaration)       \
    Declaration;                                               \
    static inline const SkType& As##Name(const sk_type& t) {   \
        return reinterpret_cast<const SkType&>(t);             \
    }                                                          \
    static inline const SkType* As##Name(const sk_type* t) {   \
        return reinterpret_cast<const SkType*>(t);             \
    }                                                          \
    static inline SkType& As##Name(sk_type& t) {               \
        return reinterpret_cast<SkType&>(t);                   \
    }                                                          \
    static inline SkType* As##Name(sk_type* t) {               \
        return reinterpret_cast<SkType*>(t);                   \
    }                                                          \
    static inline const sk_type& To##Name(const SkType& t) {   \
        return reinterpret_cast<const sk_type&>(t);            \
    }                                                          \
    static inline const sk_type* To##Name(const SkType* t) {   \
        return reinterpret_cast<const sk_type*>(t);            \
    }                                                          \
    static inline sk_type& To##Name(SkType& t) {               \
        return reinterpret_cast<sk_type&>(t);                  \
    }                                                          \
    static inline sk_type* To##Name(SkType* t) {               \
        return reinterpret_cast<sk_type*>(t);                  \
    }

#define DEF_CLASS_MAP(SkType, sk_type, Name)                   \
    DEF_MAP_DECL(SkType, sk_type, Name, class SkType)

#define DEF_STRUCT_MAP(SkType, sk_type, Name)                  \
    DEF_MAP_DECL(SkType, sk_type, Name, struct SkType)

#define DEF_MAP(SkType, sk_type, Name)                         \
    DEF_MAP_DECL(SkType, sk_type, Name, )


DEF_CLASS_MAP(SkBitmap, sk_bitmap_t, Bitmap)
DEF_CLASS_MAP(SkCanvas, sk_canvas_t, Canvas)
DEF_CLASS_MAP(SkColorFilter, sk_colorfilter_t, ColorFilter)
DEF_CLASS_MAP(SkColorSpace, sk_colorspace_t, ColorSpace)
DEF_CLASS_MAP(SkData, sk_data_t, Data)
DEF_CLASS_MAP(SkFont, sk_font_t, Font)
DEF_CLASS_MAP(SkFontMgr, sk_fontmgr_t, FontMgr)
DEF_CLASS_MAP(SkFontStyle, sk_fontstyle_t, FontStyle)
DEF_CLASS_MAP(SkImageFilter, sk_imagefilter_t, ImageFilter)
DEF_CLASS_MAP(SkMaskFilter, sk_maskfilter_t, MaskFilter)
DEF_CLASS_MAP(SkPaint, sk_paint_t, Paint)
DEF_CLASS_MAP(SkPath, sk_path_t, Path)
DEF_CLASS_MAP(SkRRect, sk_rrect_t, RRect)
DEF_CLASS_MAP(SkShader, sk_shader_t, Shader)
DEF_CLASS_MAP(SkString, sk_string_t, String)
DEF_CLASS_MAP(SkSurface, sk_surface_t, Surface)
DEF_CLASS_MAP(SkSurfaceProps, sk_surfaceprops_t, SurfaceProps)
DEF_CLASS_MAP(SkTextBlob, sk_textblob_t, TextBlob)
DEF_CLASS_MAP(SkTextBlobBuilder, sk_textblob_builder_t, TextBlobBuilder)
DEF_CLASS_MAP(SkTypeface, sk_typeface_t, Typeface)

DEF_CLASS_MAP(GrDirectContext, gr_direct_context_t, GrDirectContext)
DEF_CLASS_MAP(GrBackendRenderTarget, gr_backendrendertarget_t, GrBackendRenderTarget)

DEF_STRUCT_MAP(SkHighContrastConfig, sk_highcontrastconfig_t, HighContrastConfig)
DEF_STRUCT_MAP(SkPoint, sk_point_t, Point)
DEF_STRUCT_MAP(SkRect, sk_rect_t, Rect)

#if SK_GL
DEF_STRUCT_MAP(GrGLFramebufferInfo, gr_gl_framebufferinfo_t, GrGLFramebufferInfo)
DEF_STRUCT_MAP(GrGLInterface, gr_glinterface_t, GrGLInterface)
#endif

#include "include/core/SkColor.h"
DEF_MAP(SkColor4f, sk_color4f_t, Color4f)

#include "include/core/SkFontMetrics.h"
DEF_MAP(SkFontMetrics, sk_fontmetrics_t, FontMetrics)

#include "include/core/SkMatrix.h"
static inline SkMatrix AsMatrix(const sk_matrix_t* matrix) {
    return SkMatrix::MakeAll(
        matrix->scaleX, matrix->skewX,  matrix->transX,
        matrix->skewY,  matrix->scaleY, matrix->transY,
        matrix->persp0, matrix->persp1, matrix->persp2);
}
static inline sk_matrix_t ToMatrix(const SkMatrix* matrix) {
    sk_matrix_t m;
    m.scaleX = matrix->get(SkMatrix::kMScaleX);
    m.skewX  = matrix->get(SkMatrix::kMSkewX);
    m.transX = matrix->get(SkMatrix::kMTransX);
    m.skewY  = matrix->get(SkMatrix::kMSkewY);
    m.scaleY = matrix->get(SkMatrix::kMScaleY);
    m.transY = matrix->get(SkMatrix::kMTransY);
    m.persp0 = matrix->get(SkMatrix::kMPersp0);
    m.persp1 = matrix->get(SkMatrix::kMPersp1);
    m.persp2 = matrix->get(SkMatrix::kMPersp2);
    return m;
}
static inline sk_matrix_t ToMatrix(const SkMatrix& matrix) {
    sk_matrix_t m;
    m.scaleX = matrix.get(SkMatrix::kMScaleX);
    m.skewX  = matrix.get(SkMatrix::kMSkewX);
    m.transX = matrix.get(SkMatrix::kMTransX);
    m.skewY  = matrix.get(SkMatrix::kMSkewY);
    m.scaleY = matrix.get(SkMatrix::kMScaleY);
    m.transY = matrix.get(SkMatrix::kMTransY);
    m.persp0 = matrix.get(SkMatrix::kMPersp0);
    m.persp1 = matrix.get(SkMatrix::kMPersp1);
    m.persp2 = matrix.get(SkMatrix::kMPersp2);
    return m;
}

#include "include/core/SkImageInfo.h"
static inline SkImageInfo AsImageInfo(const sk_imageinfo_t* info) {
    return SkImageInfo::Make(
        info->width,
        info->height,
        (SkColorType)info->colorType,
        (SkAlphaType)info->alphaType,
        sk_ref_sp(AsColorSpace(info->colorspace)));
}
static inline sk_imageinfo_t ToImageInfo(const SkImageInfo info) {
    return {
        ToColorSpace(info.refColorSpace().release()),
        info.width(),
        info.height(),
        (sk_colortype_t)info.colorType(),
        (sk_alphatype_t)info.alphaType(),
    };
}
static inline const SkImageInfo* AsImageInfo(sk_imageinfo_t* cinfo) {
    return reinterpret_cast<const SkImageInfo*>(cinfo);
}
static inline sk_imageinfo_t* ToImageInfo(SkImageInfo* info) {
    return reinterpret_cast<sk_imageinfo_t*>(info);
}

#include "include/core/SkTextBlob.h"
static inline SkTextBlobBuilder::RunBuffer AsTextBlobBuilderRunBuffer(const sk_textblob_builder_runbuffer_t* runbuffer) {
    return {
        (SkGlyphID*)runbuffer->glyphs,
        (SkScalar*)runbuffer->pos,
        (char*)runbuffer->utf8text,
        (uint32_t*)runbuffer->clusters,
    };
}
static inline sk_textblob_builder_runbuffer_t ToTextBlobBuilderRunBuffer(const SkTextBlobBuilder::RunBuffer runbuffer) {
    return {
        runbuffer.glyphs,
        runbuffer.pos,
        runbuffer.utf8text,
        runbuffer.clusters,
    };
}

static inline SkImageFilters::CropRect AsImageFiltersCropRect(const sk_rect_t *rect) {
    if (!rect) {
        return SkImageFilters::CropRect();
    }

    return SkImageFilters::CropRect(AsRect(rect));
}
#if SK_SUPPORT_GPU
// GPU specific


#if SK_METAL

static inline GrMtlTextureInfo AsGrMtlTextureInfo(const gr_metal_textureinfo_t* mtlInfo) {
    GrMtlTextureInfo info;
    info.fTexture.retain(mtlInfo->fTexture);
    return info;
}

#endif // SK_METAL

#if SK_DIRECT3D

static inline GrD3DBackendContext AsGrD3DBackendContext(const gr_d3d_backendcontext_t* context) {
    GrD3DBackendContext ctx = {};
    ctx.fAdapter.reset((IDXGIAdapter1*)context->fAdapter);
    ctx.fDevice.reset((ID3D12Device*)context->fDevice);
    ctx.fQueue.reset((ID3D12CommandQueue*)context->fQueue);
    ctx.fProtectedContext = context->fProtectedContext ? GrProtected::kYes : GrProtected::kNo;
    return ctx;
}

static inline GrD3DTextureResourceInfo AsGrD3DTextureResourceInfo(
        const gr_d3d_textureresourceinfo_t* context) {
    GrD3DTextureResourceInfo ctx((ID3D12Resource*)context->fResource,
                                 nullptr,
                                 (D3D12_RESOURCE_STATES)context->fResourceState,
                                 (DXGI_FORMAT)context->fFormat,
                                 context->fSampleCount,
                                 1,
                                 0,
                                 context->fProtected ? GrProtected::kYes : GrProtected::kNo);
    return ctx;
}
#endif  // SK_DIRECT3D

#endif  // SK_SUPPORT_GPU

#endif
