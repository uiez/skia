/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "src/c/sk_types_priv.h"
#include "include/core/SkColorSpace.h"
#include "include/core/SkImage.h"
#include "include/core/SkShader.h"
#include "include/core/SkClipOp.h"
#include "include/core/SkSurfaceProps.h"
#include "include/effects/SkBlurMaskFilter.h"
#include "include/effects/SkDropShadowImageFilter.h"
#include "include/effects/SkHighContrastFilter.h"

#if SK_SUPPORT_GPU
#include "include/gpu/GrTypes.h"
#include "include/gpu/GrContextOptions.h"
#endif

#if __cplusplus >= 199711L

#define ASSERT_MSG(SK, C) "ABI changed, you must write a enumeration mapper for " SK_TO_STRING(#SK) " to " SK_TO_STRING(#C) "."

// sk_font_style_slant_t
static_assert ((int)SkFontStyle::Slant::kUpright_Slant   == (int)UPRIGHT_SK_FONT_STYLE_SLANT,   ASSERT_MSG(SkFontStyle::Slant, sk_font_style_slant_t));
static_assert ((int)SkFontStyle::Slant::kItalic_Slant    == (int)ITALIC_SK_FONT_STYLE_SLANT,    ASSERT_MSG(SkFontStyle::Slant, sk_font_style_slant_t));
static_assert ((int)SkFontStyle::Slant::kOblique_Slant   == (int)OBLIQUE_SK_FONT_STYLE_SLANT,   ASSERT_MSG(SkFontStyle::Slant, sk_font_style_slant_t));

// sk_path_add_mode_t
static_assert ((int)SkPath::AddPathMode::kAppend_AddPathMode   == (int)APPEND_SK_PATH_ADD_MODE,   ASSERT_MSG(SkPath::AddPathMode, sk_path_add_mode_t));
static_assert ((int)SkPath::AddPathMode::kExtend_AddPathMode   == (int)EXTEND_SK_PATH_ADD_MODE,   ASSERT_MSG(SkPath::AddPathMode, sk_path_add_mode_t));

// sk_path_direction_t
static_assert ((int)SkPathDirection::kCCW   == (int)CCW_SK_PATH_DIRECTION,   ASSERT_MSG(SkPathDirection, sk_path_direction_t));
static_assert ((int)SkPathDirection::kCW    == (int)CW_SK_PATH_DIRECTION,    ASSERT_MSG(SkPathDirection, sk_path_direction_t));

// sk_path_arc_size_t
static_assert ((int)SkPath::ArcSize::kLarge_ArcSize   == (int)LARGE_SK_PATH_ARC_SIZE,   ASSERT_MSG(SkPath::ArcSize, sk_path_arc_size_t));
static_assert ((int)SkPath::ArcSize::kSmall_ArcSize   == (int)SMALL_SK_PATH_ARC_SIZE,   ASSERT_MSG(SkPath::ArcSize, sk_path_arc_size_t));

// sk_path_filltype_t
static_assert ((int)SkPathFillType::kWinding          == (int)WINDING_SK_PATH_FILLTYPE,           ASSERT_MSG(SkPathFillType, sk_path_filltype_t));
static_assert ((int)SkPathFillType::kEvenOdd          == (int)EVENODD_SK_PATH_FILLTYPE,           ASSERT_MSG(SkPathFillType, sk_path_filltype_t));
static_assert ((int)SkPathFillType::kInverseWinding   == (int)INVERSE_WINDING_SK_PATH_FILLTYPE,   ASSERT_MSG(SkPathFillType, sk_path_filltype_t));
static_assert ((int)SkPathFillType::kInverseEvenOdd   == (int)INVERSE_EVENODD_SK_PATH_FILLTYPE,   ASSERT_MSG(SkPathFillType, sk_path_filltype_t));

// sk_filter_quality_t
static_assert ((int)SkFilterQuality::kNone_SkFilterQuality     == (int)NONE_SK_FILTER_QUALITY,     ASSERT_MSG(SkFilterQuality, sk_filter_quality_t));
static_assert ((int)SkFilterQuality::kLow_SkFilterQuality      == (int)LOW_SK_FILTER_QUALITY,      ASSERT_MSG(SkFilterQuality, sk_filter_quality_t));
static_assert ((int)SkFilterQuality::kMedium_SkFilterQuality   == (int)MEDIUM_SK_FILTER_QUALITY,   ASSERT_MSG(SkFilterQuality, sk_filter_quality_t));
static_assert ((int)SkFilterQuality::kHigh_SkFilterQuality     == (int)HIGH_SK_FILTER_QUALITY,     ASSERT_MSG(SkFilterQuality, sk_filter_quality_t));

// sk_crop_rect_flags_t
static_assert ((int)SkImageFilter::CropRect::CropEdge::kHasLeft_CropEdge     == (int)HAS_LEFT_SK_CROP_RECT_FLAG,     ASSERT_MSG(SkImageFilter::CropRect::CropEdge, sk_crop_rect_flags_t));
static_assert ((int)SkImageFilter::CropRect::CropEdge::kHasTop_CropEdge      == (int)HAS_TOP_SK_CROP_RECT_FLAG,      ASSERT_MSG(SkImageFilter::CropRect::CropEdge, sk_crop_rect_flags_t));
static_assert ((int)SkImageFilter::CropRect::CropEdge::kHasWidth_CropEdge    == (int)HAS_WIDTH_SK_CROP_RECT_FLAG,    ASSERT_MSG(SkImageFilter::CropRect::CropEdge, sk_crop_rect_flags_t));
static_assert ((int)SkImageFilter::CropRect::CropEdge::kHasHeight_CropEdge   == (int)HAS_HEIGHT_SK_CROP_RECT_FLAG,   ASSERT_MSG(SkImageFilter::CropRect::CropEdge, sk_crop_rect_flags_t));
static_assert ((int)SkImageFilter::CropRect::CropEdge::kHasAll_CropEdge      == (int)HAS_ALL_SK_CROP_RECT_FLAG,      ASSERT_MSG(SkImageFilter::CropRect::CropEdge, sk_crop_rect_flags_t));

// sk_blendmode_t
static_assert ((int)SkBlendMode::kClear        == (int)CLEAR_SK_BLENDMODE,        ASSERT_MSG(SkBlendMode, sk_blendmode_t));
static_assert ((int)SkBlendMode::kSrc          == (int)SRC_SK_BLENDMODE,          ASSERT_MSG(SkBlendMode, sk_blendmode_t));
static_assert ((int)SkBlendMode::kDst          == (int)DST_SK_BLENDMODE,          ASSERT_MSG(SkBlendMode, sk_blendmode_t));
static_assert ((int)SkBlendMode::kSrcOver      == (int)SRCOVER_SK_BLENDMODE,      ASSERT_MSG(SkBlendMode, sk_blendmode_t));
static_assert ((int)SkBlendMode::kDstOver      == (int)DSTOVER_SK_BLENDMODE,      ASSERT_MSG(SkBlendMode, sk_blendmode_t));
static_assert ((int)SkBlendMode::kSrcIn        == (int)SRCIN_SK_BLENDMODE,        ASSERT_MSG(SkBlendMode, sk_blendmode_t));
static_assert ((int)SkBlendMode::kDstIn        == (int)DSTIN_SK_BLENDMODE,        ASSERT_MSG(SkBlendMode, sk_blendmode_t));
static_assert ((int)SkBlendMode::kSrcOut       == (int)SRCOUT_SK_BLENDMODE,       ASSERT_MSG(SkBlendMode, sk_blendmode_t));
static_assert ((int)SkBlendMode::kDstOut       == (int)DSTOUT_SK_BLENDMODE,       ASSERT_MSG(SkBlendMode, sk_blendmode_t));
static_assert ((int)SkBlendMode::kSrcATop      == (int)SRCATOP_SK_BLENDMODE,      ASSERT_MSG(SkBlendMode, sk_blendmode_t));
static_assert ((int)SkBlendMode::kDstATop      == (int)DSTATOP_SK_BLENDMODE,      ASSERT_MSG(SkBlendMode, sk_blendmode_t));
static_assert ((int)SkBlendMode::kXor          == (int)XOR_SK_BLENDMODE,          ASSERT_MSG(SkBlendMode, sk_blendmode_t));
static_assert ((int)SkBlendMode::kPlus         == (int)PLUS_SK_BLENDMODE,         ASSERT_MSG(SkBlendMode, sk_blendmode_t));
static_assert ((int)SkBlendMode::kModulate     == (int)MODULATE_SK_BLENDMODE,     ASSERT_MSG(SkBlendMode, sk_blendmode_t));
static_assert ((int)SkBlendMode::kScreen       == (int)SCREEN_SK_BLENDMODE,       ASSERT_MSG(SkBlendMode, sk_blendmode_t));
static_assert ((int)SkBlendMode::kOverlay      == (int)OVERLAY_SK_BLENDMODE,      ASSERT_MSG(SkBlendMode, sk_blendmode_t));
static_assert ((int)SkBlendMode::kDarken       == (int)DARKEN_SK_BLENDMODE,       ASSERT_MSG(SkBlendMode, sk_blendmode_t));
static_assert ((int)SkBlendMode::kLighten      == (int)LIGHTEN_SK_BLENDMODE,      ASSERT_MSG(SkBlendMode, sk_blendmode_t));
static_assert ((int)SkBlendMode::kColorDodge   == (int)COLORDODGE_SK_BLENDMODE,   ASSERT_MSG(SkBlendMode, sk_blendmode_t));
static_assert ((int)SkBlendMode::kColorBurn    == (int)COLORBURN_SK_BLENDMODE,    ASSERT_MSG(SkBlendMode, sk_blendmode_t));
static_assert ((int)SkBlendMode::kHardLight    == (int)HARDLIGHT_SK_BLENDMODE,    ASSERT_MSG(SkBlendMode, sk_blendmode_t));
static_assert ((int)SkBlendMode::kSoftLight    == (int)SOFTLIGHT_SK_BLENDMODE,    ASSERT_MSG(SkBlendMode, sk_blendmode_t));
static_assert ((int)SkBlendMode::kDifference   == (int)DIFFERENCE_SK_BLENDMODE,   ASSERT_MSG(SkBlendMode, sk_blendmode_t));
static_assert ((int)SkBlendMode::kExclusion    == (int)EXCLUSION_SK_BLENDMODE,    ASSERT_MSG(SkBlendMode, sk_blendmode_t));
static_assert ((int)SkBlendMode::kMultiply     == (int)MULTIPLY_SK_BLENDMODE,     ASSERT_MSG(SkBlendMode, sk_blendmode_t));
static_assert ((int)SkBlendMode::kHue          == (int)HUE_SK_BLENDMODE,          ASSERT_MSG(SkBlendMode, sk_blendmode_t));
static_assert ((int)SkBlendMode::kSaturation   == (int)SATURATION_SK_BLENDMODE,   ASSERT_MSG(SkBlendMode, sk_blendmode_t));
static_assert ((int)SkBlendMode::kColor        == (int)COLOR_SK_BLENDMODE,        ASSERT_MSG(SkBlendMode, sk_blendmode_t));
static_assert ((int)SkBlendMode::kLuminosity   == (int)LUMINOSITY_SK_BLENDMODE,   ASSERT_MSG(SkBlendMode, sk_blendmode_t));

// sk_colortype_t
static_assert ((int)SkColorType::kUnknown_SkColorType              == (int)UNKNOWN_SK_COLORTYPE,              ASSERT_MSG(SkColorType, sk_colortype_t));
static_assert ((int)SkColorType::kAlpha_8_SkColorType              == (int)ALPHA_8_SK_COLORTYPE,              ASSERT_MSG(SkColorType, sk_colortype_t));
static_assert ((int)SkColorType::kRGB_565_SkColorType              == (int)RGB_565_SK_COLORTYPE,              ASSERT_MSG(SkColorType, sk_colortype_t));
static_assert ((int)SkColorType::kARGB_4444_SkColorType            == (int)ARGB_4444_SK_COLORTYPE,            ASSERT_MSG(SkColorType, sk_colortype_t));
static_assert ((int)SkColorType::kRGBA_8888_SkColorType            == (int)RGBA_8888_SK_COLORTYPE,            ASSERT_MSG(SkColorType, sk_colortype_t));
static_assert ((int)SkColorType::kBGRA_8888_SkColorType            == (int)BGRA_8888_SK_COLORTYPE,            ASSERT_MSG(SkColorType, sk_colortype_t));
static_assert ((int)SkColorType::kRGB_888x_SkColorType             == (int)RGB_888X_SK_COLORTYPE,             ASSERT_MSG(SkColorType, sk_colortype_t));
static_assert ((int)SkColorType::kRGBA_1010102_SkColorType         == (int)RGBA_1010102_SK_COLORTYPE,         ASSERT_MSG(SkColorType, sk_colortype_t));
static_assert ((int)SkColorType::kBGRA_1010102_SkColorType         == (int)BGRA_1010102_SK_COLORTYPE,         ASSERT_MSG(SkColorType, sk_colortype_t));
static_assert ((int)SkColorType::kRGB_101010x_SkColorType          == (int)RGB_101010X_SK_COLORTYPE,          ASSERT_MSG(SkColorType, sk_colortype_t));
static_assert ((int)SkColorType::kBGR_101010x_SkColorType          == (int)BGR_101010X_SK_COLORTYPE,          ASSERT_MSG(SkColorType, sk_colortype_t));
static_assert ((int)SkColorType::kGray_8_SkColorType               == (int)GRAY_8_SK_COLORTYPE,               ASSERT_MSG(SkColorType, sk_colortype_t));
static_assert ((int)SkColorType::kRGBA_F16Norm_SkColorType         == (int)RGBA_F16_NORM_SK_COLORTYPE,        ASSERT_MSG(SkColorType, sk_colortype_t));
static_assert ((int)SkColorType::kRGBA_F16_SkColorType             == (int)RGBA_F16_SK_COLORTYPE,             ASSERT_MSG(SkColorType, sk_colortype_t));
static_assert ((int)SkColorType::kRGBA_F32_SkColorType             == (int)RGBA_F32_SK_COLORTYPE,             ASSERT_MSG(SkColorType, sk_colortype_t));
static_assert ((int)SkColorType::kR8G8_unorm_SkColorType           == (int)R8G8_UNORM_SK_COLORTYPE,           ASSERT_MSG(SkColorType, sk_colortype_t));
static_assert ((int)SkColorType::kA16_unorm_SkColorType            == (int)A16_UNORM_SK_COLORTYPE,            ASSERT_MSG(SkColorType, sk_colortype_t));
static_assert ((int)SkColorType::kR16G16_unorm_SkColorType         == (int)R16G16_UNORM_SK_COLORTYPE,         ASSERT_MSG(SkColorType, sk_colortype_t));
static_assert ((int)SkColorType::kA16_float_SkColorType            == (int)A16_FLOAT_SK_COLORTYPE,            ASSERT_MSG(SkColorType, sk_colortype_t));
static_assert ((int)SkColorType::kR16G16_float_SkColorType         == (int)R16G16_FLOAT_SK_COLORTYPE,         ASSERT_MSG(SkColorType, sk_colortype_t));
static_assert ((int)SkColorType::kR16G16B16A16_unorm_SkColorType   == (int)R16G16B16A16_UNORM_SK_COLORTYPE,   ASSERT_MSG(SkColorType, sk_colortype_t));

// sk_alphatype_t
static_assert ((int)SkAlphaType::kUnknown_SkAlphaType    == (int)UNKNOWN_SK_ALPHATYPE,    ASSERT_MSG(SkAlphaType, sk_alphatype_t));
static_assert ((int)SkAlphaType::kOpaque_SkAlphaType     == (int)OPAQUE_SK_ALPHATYPE,     ASSERT_MSG(SkAlphaType, sk_alphatype_t));
static_assert ((int)SkAlphaType::kPremul_SkAlphaType     == (int)PREMUL_SK_ALPHATYPE,     ASSERT_MSG(SkAlphaType, sk_alphatype_t));
static_assert ((int)SkAlphaType::kUnpremul_SkAlphaType   == (int)UNPREMUL_SK_ALPHATYPE,   ASSERT_MSG(SkAlphaType, sk_alphatype_t));

// sk_pixelgeometry_t
static_assert ((int)SkPixelGeometry::kUnknown_SkPixelGeometry   == (int)UNKNOWN_SK_PIXELGEOMETRY,   ASSERT_MSG(SkPixelGeometry, sk_pixelgeometry_t));
static_assert ((int)SkPixelGeometry::kRGB_H_SkPixelGeometry     == (int)RGB_H_SK_PIXELGEOMETRY,     ASSERT_MSG(SkPixelGeometry, sk_pixelgeometry_t));
static_assert ((int)SkPixelGeometry::kBGR_H_SkPixelGeometry     == (int)BGR_H_SK_PIXELGEOMETRY,     ASSERT_MSG(SkPixelGeometry, sk_pixelgeometry_t));
static_assert ((int)SkPixelGeometry::kRGB_V_SkPixelGeometry     == (int)RGB_V_SK_PIXELGEOMETRY,     ASSERT_MSG(SkPixelGeometry, sk_pixelgeometry_t));
static_assert ((int)SkPixelGeometry::kBGR_V_SkPixelGeometry     == (int)BGR_V_SK_PIXELGEOMETRY,     ASSERT_MSG(SkPixelGeometry, sk_pixelgeometry_t));

// sk_shader_tilemode_t
static_assert ((int)SkTileMode::kClamp    == (int)CLAMP_SK_SHADER_TILEMODE,    ASSERT_MSG(SkTileMode, sk_shader_tilemode_t));
static_assert ((int)SkTileMode::kRepeat   == (int)REPEAT_SK_SHADER_TILEMODE,   ASSERT_MSG(SkTileMode, sk_shader_tilemode_t));
static_assert ((int)SkTileMode::kMirror   == (int)MIRROR_SK_SHADER_TILEMODE,   ASSERT_MSG(SkTileMode, sk_shader_tilemode_t));
static_assert ((int)SkTileMode::kDecal    == (int)DECAL_SK_SHADER_TILEMODE,    ASSERT_MSG(SkTileMode, sk_shader_tilemode_t));

// sk_blurstyle_t
static_assert ((int)SkBlurStyle::kNormal_SkBlurStyle   == (int)NORMAL_SK_BLUR_STYLE,   ASSERT_MSG(SkBlurStyle, sk_blurstyle_t));
static_assert ((int)SkBlurStyle::kSolid_SkBlurStyle    == (int)SOLID_SK_BLUR_STYLE,    ASSERT_MSG(SkBlurStyle, sk_blurstyle_t));
static_assert ((int)SkBlurStyle::kOuter_SkBlurStyle    == (int)OUTER_SK_BLUR_STYLE,    ASSERT_MSG(SkBlurStyle, sk_blurstyle_t));
static_assert ((int)SkBlurStyle::kInner_SkBlurStyle    == (int)INNER_SK_BLUR_STYLE,    ASSERT_MSG(SkBlurStyle, sk_blurstyle_t));

// sk_stroke_cap_t
static_assert ((int)SkPaint::Cap::kButt_Cap     == (int)BUTT_SK_STROKE_CAP,     ASSERT_MSG(SkPaint::Cap, sk_stroke_cap_t));
static_assert ((int)SkPaint::Cap::kRound_Cap    == (int)ROUND_SK_STROKE_CAP,    ASSERT_MSG(SkPaint::Cap, sk_stroke_cap_t));
static_assert ((int)SkPaint::Cap::kSquare_Cap   == (int)SQUARE_SK_STROKE_CAP,   ASSERT_MSG(SkPaint::Cap, sk_stroke_cap_t));

// sk_stroke_join_t
static_assert ((int)SkPaint::Join::kMiter_Join   == (int)MITER_SK_STROKE_JOIN,   ASSERT_MSG(SkPaint::Join, sk_stroke_join_t));
static_assert ((int)SkPaint::Join::kRound_Join   == (int)ROUND_SK_STROKE_JOIN,   ASSERT_MSG(SkPaint::Join, sk_stroke_join_t));
static_assert ((int)SkPaint::Join::kBevel_Join   == (int)BEVEL_SK_STROKE_JOIN,   ASSERT_MSG(SkPaint::Join, sk_stroke_join_t));

// sk_clipop_t
static_assert ((int)SkClipOp::kDifference   == (int)DIFFERENCE_SK_CLIPOP,           ASSERT_MSG(SkClipOp, sk_clipop_t));
static_assert ((int)SkClipOp::kIntersect    == (int)INTERSECT_SK_CLIPOP,            ASSERT_MSG(SkClipOp, sk_clipop_t));

// sk_paint_style_t
static_assert ((int)SkPaint::Style::kFill_Style            == (int)FILL_SK_PAINT_STYLE,              ASSERT_MSG(SkPaint::Style, sk_paint_style_t));
static_assert ((int)SkPaint::Style::kStrokeAndFill_Style   == (int)STROKE_AND_FILL_SK_PAINT_STYLE,   ASSERT_MSG(SkPaint::Style, sk_paint_style_t));
static_assert ((int)SkPaint::Style::kStroke_Style          == (int)STROKE_SK_PAINT_STYLE,            ASSERT_MSG(SkPaint::Style, sk_paint_style_t));

// sk_font_hinting_t
static_assert ((int)SkFontHinting::kNone     == (int)NONE_SK_FONT_HINTING,     ASSERT_MSG(SkFontHinting, sk_font_hinting_t));
static_assert ((int)SkFontHinting::kSlight   == (int)SLIGHT_SK_FONT_HINTING,   ASSERT_MSG(SkFontHinting, sk_font_hinting_t));
static_assert ((int)SkFontHinting::kNormal   == (int)NORMAL_SK_FONT_HINTING,   ASSERT_MSG(SkFontHinting, sk_font_hinting_t));
static_assert ((int)SkFontHinting::kFull     == (int)FULL_SK_FONT_HINTING,     ASSERT_MSG(SkFontHinting, sk_font_hinting_t));

// sk_surfaceprops_flags_t
static_assert ((int)SkSurfaceProps::Flags::kUseDeviceIndependentFonts_Flag   == (int)USE_DEVICE_INDEPENDENT_FONTS_SK_SURFACE_PROPS_FLAGS,   ASSERT_MSG(SkSurfaceProps::Flags, sk_surfaceprops_flags_t));

// sk_highcontrastconfig_invertstyle_t
static_assert ((int)SkHighContrastConfig::InvertStyle::kNoInvert           == (int)NO_INVERT_SK_HIGH_CONTRAST_CONFIG_INVERT_STYLE,           ASSERT_MSG(SkHighContrastConfig::InvertStyle, sk_highcontrastconfig_invertstyle_t));
static_assert ((int)SkHighContrastConfig::InvertStyle::kInvertBrightness   == (int)INVERT_BRIGHTNESS_SK_HIGH_CONTRAST_CONFIG_INVERT_STYLE,   ASSERT_MSG(SkHighContrastConfig::InvertStyle, sk_highcontrastconfig_invertstyle_t));
static_assert ((int)SkHighContrastConfig::InvertStyle::kInvertLightness    == (int)INVERT_LIGHTNESS_SK_HIGH_CONTRAST_CONFIG_INVERT_STYLE,    ASSERT_MSG(SkHighContrastConfig::InvertStyle, sk_highcontrastconfig_invertstyle_t));

#if SK_SUPPORT_GPU

// gr_surfaceorigin_t
static_assert ((int)GrSurfaceOrigin::kTopLeft_GrSurfaceOrigin      == (int)TOP_LEFT_GR_SURFACE_ORIGIN,      ASSERT_MSG(GrSurfaceOrigin, gr_surfaceorigin_t));
static_assert ((int)GrSurfaceOrigin::kBottomLeft_GrSurfaceOrigin   == (int)BOTTOM_LEFT_GR_SURFACE_ORIGIN,   ASSERT_MSG(GrSurfaceOrigin, gr_surfaceorigin_t));

#endif

#endif
