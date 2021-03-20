/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk_types_DEFINED
#define sk_types_DEFINED

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
    #define SK_C_PLUS_PLUS_BEGIN_GUARD    extern "C" {
    #define SK_C_PLUS_PLUS_END_GUARD      }
#else
    #include <stdbool.h>
    #define SK_C_PLUS_PLUS_BEGIN_GUARD
    #define SK_C_PLUS_PLUS_END_GUARD
#endif

#if !defined(SK_C_API)
    #if defined(SKIA_C_DLL)
        #if defined(_MSC_VER)
            #if SKIA_IMPLEMENTATION
                #define SK_C_API __declspec(dllexport)
            #else
                #define SK_C_API __declspec(dllimport)
            #endif
        #else
            #define SK_C_API __attribute__((visibility("default")))
        #endif
    #else
        #define SK_C_API
    #endif
#endif

#if !defined(SK_TO_STRING)
    #define SK_TO_STRING(X) SK_TO_STRING_IMPL(X)
    #define SK_TO_STRING_IMPL(X) #X
#endif

#ifndef SK_C_INCREMENT
#define SK_C_INCREMENT 0
#endif

///////////////////////////////////////////////////////////////////////////////////////

SK_C_PLUS_PLUS_BEGIN_GUARD

typedef uint32_t sk_color_t;

/* This macro assumes all arguments are >=0 and <=255. */
#define sk_color_set_argb(a, r, g, b)   (((a) << 24) | ((r) << 16) | ((g) << 8) | (b))
#define sk_color_get_a(c)               (((c) >> 24) & 0xFF)
#define sk_color_get_r(c)               (((c) >> 16) & 0xFF)
#define sk_color_get_g(c)               (((c) >>  8) & 0xFF)
#define sk_color_get_b(c)               (((c) >>  0) & 0xFF)

typedef struct sk_color4f_t {
    float fR;
    float fG;
    float fB;
    float fA;
} sk_color4f_t;

typedef enum {
    UNKNOWN_SK_COLORTYPE = 0,
    ALPHA_8_SK_COLORTYPE,
    RGB_565_SK_COLORTYPE,
    ARGB_4444_SK_COLORTYPE,
    RGBA_8888_SK_COLORTYPE,
    RGB_888X_SK_COLORTYPE,
    BGRA_8888_SK_COLORTYPE,
    RGBA_1010102_SK_COLORTYPE,
    BGRA_1010102_SK_COLORTYPE,
    RGB_101010X_SK_COLORTYPE,
    BGR_101010X_SK_COLORTYPE,
    GRAY_8_SK_COLORTYPE,
    RGBA_F16_NORM_SK_COLORTYPE,
    RGBA_F16_SK_COLORTYPE,
    RGBA_F32_SK_COLORTYPE,

    // READONLY
    R8G8_UNORM_SK_COLORTYPE,
    A16_FLOAT_SK_COLORTYPE,
    R16G16_FLOAT_SK_COLORTYPE,
    A16_UNORM_SK_COLORTYPE,
    R16G16_UNORM_SK_COLORTYPE,
    R16G16B16A16_UNORM_SK_COLORTYPE,
} sk_colortype_t;

typedef enum {
    UNKNOWN_SK_ALPHATYPE,
    OPAQUE_SK_ALPHATYPE,
    PREMUL_SK_ALPHATYPE,
    UNPREMUL_SK_ALPHATYPE,
} sk_alphatype_t;

typedef enum {
    UNKNOWN_SK_PIXELGEOMETRY,
    RGB_H_SK_PIXELGEOMETRY,
    BGR_H_SK_PIXELGEOMETRY,
    RGB_V_SK_PIXELGEOMETRY,
    BGR_V_SK_PIXELGEOMETRY,
} sk_pixelgeometry_t;

typedef enum {
    NONE_SK_SURFACE_PROPS_FLAGS = 0,
    USE_DEVICE_INDEPENDENT_FONTS_SK_SURFACE_PROPS_FLAGS = 1 << 0,
} sk_surfaceprops_flags_t;

typedef struct sk_surfaceprops_t sk_surfaceprops_t;

typedef struct {
    float   x;
    float   y;
} sk_point_t;

typedef sk_point_t sk_vector_t;

typedef struct {
    float   left;
    float   top;
    float   right;
    float   bottom;
} sk_rect_t;

typedef struct {
    float scaleX, skewX, transX;
    float skewY, scaleY, transY;
    float persp0, persp1, persp2;
} sk_matrix_t;

/**
    A sk_canvas_t encapsulates all of the state about drawing into a
    destination This includes a reference to the destination itself,
    and a stack of matrix/clip values.
*/
typedef struct sk_canvas_t sk_canvas_t;
/**
    A sk_data_ holds an immutable data buffer.
*/
typedef struct sk_data_t sk_data_t;

/**
    A sk_maskfilter_t is an object that perform transformations on an
    alpha-channel mask before drawing it; it may be installed into a
    sk_paint_t.  Each time a primitive is drawn, it is first
    scan-converted into a alpha mask, which os handed to the
    maskfilter, which may create a new mask is to render into the
    destination.
 */
typedef struct sk_maskfilter_t sk_maskfilter_t;
/**
    A sk_paint_t holds the style and color information about how to
    draw geometries, text and bitmaps.
*/
typedef struct sk_paint_t sk_paint_t;
typedef struct sk_font_t sk_font_t;
/**
    A sk_path_t encapsulates compound (multiple contour) geometric
    paths consisting of straight line segments, quadratic curves, and
    cubic curves.
*/
typedef struct sk_path_t sk_path_t;
/**
    A sk_shader_t specifies the source color(s) for what is being drawn. If a
    paint has no shader, then the paint's color is used. If the paint
    has a shader, then the shader's color(s) are use instead, but they
    are modulated by the paint's alpha.
*/
typedef struct sk_shader_t sk_shader_t;
/**
    A sk_surface_t holds the destination for drawing to a canvas. For
    raster drawing, the destination is an array of pixels in memory.
    For GPU drawing, the destination is a texture or a framebuffer.
*/
typedef struct sk_surface_t sk_surface_t;

typedef enum {
    CLEAR_SK_BLENDMODE,
    SRC_SK_BLENDMODE,
    DST_SK_BLENDMODE,
    SRCOVER_SK_BLENDMODE,
    DSTOVER_SK_BLENDMODE,
    SRCIN_SK_BLENDMODE,
    DSTIN_SK_BLENDMODE,
    SRCOUT_SK_BLENDMODE,
    DSTOUT_SK_BLENDMODE,
    SRCATOP_SK_BLENDMODE,
    DSTATOP_SK_BLENDMODE,
    XOR_SK_BLENDMODE,
    PLUS_SK_BLENDMODE,
    MODULATE_SK_BLENDMODE,
    SCREEN_SK_BLENDMODE,
    OVERLAY_SK_BLENDMODE,
    DARKEN_SK_BLENDMODE,
    LIGHTEN_SK_BLENDMODE,
    COLORDODGE_SK_BLENDMODE,
    COLORBURN_SK_BLENDMODE,
    HARDLIGHT_SK_BLENDMODE,
    SOFTLIGHT_SK_BLENDMODE,
    DIFFERENCE_SK_BLENDMODE,
    EXCLUSION_SK_BLENDMODE,
    MULTIPLY_SK_BLENDMODE,
    HUE_SK_BLENDMODE,
    SATURATION_SK_BLENDMODE,
    COLOR_SK_BLENDMODE,
    LUMINOSITY_SK_BLENDMODE,
} sk_blendmode_t;

//////////////////////////////////////////////////////////////////////////////////////////


typedef struct {
    uint32_t fFlags;
    float    fTop;
    float    fAscent;
    float    fDescent;
    float    fBottom;
    float    fLeading;
    float    fAvgCharWidth;
    float    fMaxCharWidth;
    float    fXMin;
    float    fXMax;
    float    fXHeight;
    float    fCapHeight;
    float    fUnderlineThickness;
    float    fUnderlinePosition;
    float    fStrikeoutThickness;
    float    fStrikeoutPosition;
} sk_fontmetrics_t;

// Flags for fFlags member of sk_fontmetrics_t
#define FONTMETRICS_FLAGS_UNDERLINE_THICKNESS_IS_VALID (1U << 0)
#define FONTMETRICS_FLAGS_UNDERLINE_POSITION_IS_VALID (1U << 1)

/**
    A lightweight managed string.
*/
typedef struct sk_string_t sk_string_t;
/**

    A sk_bitmap_t is an abstraction that specifies a raster bitmap.
*/
typedef struct sk_bitmap_t sk_bitmap_t;
typedef struct sk_colorfilter_t sk_colorfilter_t;
typedef struct sk_imagefilter_t sk_imagefilter_t;

/**
   A sk_typeface_t pecifies the typeface and intrinsic style of a font.
    This is used in the paint, along with optionally algorithmic settings like
    textSize, textSkewX, textScaleX, kFakeBoldText_Mask, to specify
    how text appears when drawn (and measured).

    Typeface objects are immutable, and so they can be shared between threads.
*/
typedef struct sk_typeface_t sk_typeface_t;

typedef enum sk_typeface_native_type_t {
    UNKNOWN_SK_TYPEFACE_NATIVE_TYPE = 0,
    CORETEXT_SK_TYPEFACE_NATIVE_TYPE = 1,
    DIRECTWRITE_SK_TYPEFACE_NATIVE_TYPE = 2,
    GDI_SK_TYPEFACE_NATIVE_TYPE = 3,
    FREETYPE_SK_TYPEFACE_NATIVE_TYPE = 4
} sk_typeface_native_type_t;

typedef uint32_t sk_font_table_tag_t;
typedef struct sk_fontmgr_t sk_fontmgr_t;
typedef struct sk_fontstyle_t sk_fontstyle_t;

typedef uint32_t sk_font_id_t;
typedef uint16_t sk_glyph_id_t;

typedef struct sk_colorspace_t sk_colorspace_t;

typedef enum {
    WINDING_SK_PATH_FILLTYPE,
    EVENODD_SK_PATH_FILLTYPE,
    INVERSE_WINDING_SK_PATH_FILLTYPE,
    INVERSE_EVENODD_SK_PATH_FILLTYPE,
} sk_path_filltype_t;

typedef enum {
    UPRIGHT_SK_FONT_STYLE_SLANT = 0,
    ITALIC_SK_FONT_STYLE_SLANT  = 1,
    OBLIQUE_SK_FONT_STYLE_SLANT = 2,
} sk_font_style_slant_t;

typedef enum {
    NONE_SK_FILTER_QUALITY,
    LOW_SK_FILTER_QUALITY,
    MEDIUM_SK_FILTER_QUALITY,
    HIGH_SK_FILTER_QUALITY
} sk_filter_quality_t;

typedef enum {
    HAS_NONE_SK_CROP_RECT_FLAG   = 0x00,
    HAS_LEFT_SK_CROP_RECT_FLAG   = 0x01,
    HAS_TOP_SK_CROP_RECT_FLAG    = 0x02,
    HAS_WIDTH_SK_CROP_RECT_FLAG  = 0x04,
    HAS_HEIGHT_SK_CROP_RECT_FLAG = 0x08,
    HAS_ALL_SK_CROP_RECT_FLAG    = 0x0F,
} sk_crop_rect_flags_t;

typedef enum {
    DIFFERENCE_SK_CLIPOP,
    INTERSECT_SK_CLIPOP,
} sk_clipop_t;

typedef enum {
    APPEND_SK_PATH_ADD_MODE,
    EXTEND_SK_PATH_ADD_MODE,
} sk_path_add_mode_t;

typedef enum {
    BUTT_SK_STROKE_CAP,
    ROUND_SK_STROKE_CAP,
    SQUARE_SK_STROKE_CAP
} sk_stroke_cap_t;

typedef enum {
    MITER_SK_STROKE_JOIN,
    ROUND_SK_STROKE_JOIN,
    BEVEL_SK_STROKE_JOIN
} sk_stroke_join_t;

typedef enum {
    CLAMP_SK_SHADER_TILEMODE,
    REPEAT_SK_SHADER_TILEMODE,
    MIRROR_SK_SHADER_TILEMODE,
    DECAL_SK_SHADER_TILEMODE,
} sk_shader_tilemode_t;

typedef enum {
    NORMAL_SK_BLUR_STYLE,   //!< fuzzy inside and outside
    SOLID_SK_BLUR_STYLE,    //!< solid inside, fuzzy outside
    OUTER_SK_BLUR_STYLE,    //!< nothing inside, fuzzy outside
    INNER_SK_BLUR_STYLE,    //!< fuzzy inside, nothing outside
} sk_blurstyle_t;

typedef enum {
    CW_SK_PATH_DIRECTION,
    CCW_SK_PATH_DIRECTION,
} sk_path_direction_t;

typedef enum {
    SMALL_SK_PATH_ARC_SIZE,
    LARGE_SK_PATH_ARC_SIZE,
} sk_path_arc_size_t;

typedef enum {
    FILL_SK_PAINT_STYLE,
    STROKE_SK_PAINT_STYLE,
    STROKE_AND_FILL_SK_PAINT_STYLE,
} sk_paint_style_t;

typedef enum {
    NONE_SK_FONT_HINTING,
    SLIGHT_SK_FONT_HINTING,
    NORMAL_SK_FONT_HINTING,
    FULL_SK_FONT_HINTING,
} sk_font_hinting_t;

typedef enum {
    ALIAS_SK_FONT_EDGING,
    ANTIALIAS_SK_FONT_EDGING,
    SUBPIXEL_ANTIALIAS_SK_FONT_EDGING,
} sk_font_edging_t;

typedef enum {
    TOP_LEFT_GR_SURFACE_ORIGIN,
    BOTTOM_LEFT_GR_SURFACE_ORIGIN,
} gr_surfaceorigin_t;


typedef struct gr_backendrendertarget_t gr_backendrendertarget_t;

typedef struct gr_direct_context_t gr_direct_context_t;

typedef struct gr_glinterface_t gr_glinterface_t;

typedef void (*gr_gl_func_ptr)(void);
typedef gr_gl_func_ptr (*gr_gl_get_proc)(void* ctx, const char* name);

typedef struct {
    unsigned int fFBOID;
    unsigned int fFormat;
} gr_gl_framebufferinfo_t;

typedef struct {
    const void* fTexture;
} gr_metal_textureinfo_t;

typedef struct dxgi_adapter1_t dxgi_adapter1_t;
typedef struct d3d12_device_t d3d12_device_t;
typedef struct d3d12_command_queue_t d3d12_command_queue_t;
typedef struct {
    const dxgi_adapter1_t*       fAdapter;
    const d3d12_device_t*        fDevice;
    const d3d12_command_queue_t* fQueue;
    bool                         fProtectedContext;
} gr_d3d_backendcontext_t;

typedef struct d3d12_resource_t d3d12_resource_t;
typedef uint32_t d3d12_resource_states_t;
typedef uint32_t dxgi_format_t;
typedef struct {
    const d3d12_resource_t* fResource;
    d3d12_resource_states_t fResourceState;
    dxgi_format_t           fFormat;
    uint32_t                fSampleCount;
    bool                    fProtected;
} gr_d3d_textureresourceinfo_t;

typedef struct {
    sk_colorspace_t* colorspace;
    int32_t          width;
    int32_t          height;
    sk_colortype_t   colorType;
    sk_alphatype_t   alphaType;
} sk_imageinfo_t;

typedef enum {
    NO_INVERT_SK_HIGH_CONTRAST_CONFIG_INVERT_STYLE,
    INVERT_BRIGHTNESS_SK_HIGH_CONTRAST_CONFIG_INVERT_STYLE,
    INVERT_LIGHTNESS_SK_HIGH_CONTRAST_CONFIG_INVERT_STYLE,
} sk_highcontrastconfig_invertstyle_t;

typedef struct {
    bool fGrayscale;
    sk_highcontrastconfig_invertstyle_t fInvertStyle;
    float fContrast;
} sk_highcontrastconfig_t;

typedef struct sk_rrect_t sk_rrect_t;

typedef struct sk_textblob_t sk_textblob_t;
typedef struct sk_textblob_builder_t sk_textblob_builder_t;

typedef struct {
    void* glyphs;
    void* pos;
    void* utf8text;
    void* clusters;
} sk_textblob_builder_runbuffer_t;

typedef enum {
    INIT_WITH_PREVIOUS_SK_CANVAS_SAVE_LAYER_FLAGS = 1 << 2,
} sk_save_layer_flags_t;

typedef struct {
    sk_rect_t bounds;
    sk_paint_t *paint;
    sk_imagefilter_t *backdrop;
    sk_save_layer_flags_t flags;
} sk_save_layer_rec_t;

SK_C_PLUS_PLUS_END_GUARD

#endif
