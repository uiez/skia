/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/core/SkColorFilter.h"
#include "include/core/SkImageFilter.h"
#include "include/core/SkRegion.h"
#include "include/effects/SkImageFilters.h"

#include "include/effects/SkAlphaThresholdFilter.h"
#include "include/effects/SkBlurImageFilter.h"
#include "include/effects/SkColorFilterImageFilter.h"
#include "include/effects/SkComposeImageFilter.h"
#include "include/effects/SkDisplacementMapEffect.h"
#include "include/effects/SkDropShadowImageFilter.h"
#include "include/effects/SkLightingImageFilter.h"
#include "include/effects/SkMagnifierImageFilter.h"
#include "include/effects/SkMatrixConvolutionImageFilter.h"
#include "include/effects/SkMergeImageFilter.h"
#include "include/effects/SkMorphologyImageFilter.h"
#include "include/effects/SkOffsetImageFilter.h"
#include "include/effects/SkTileImageFilter.h"
#include "include/effects/SkXfermodeImageFilter.h"
#include "include/effects/SkArithmeticImageFilter.h"
#include "include/effects/SkImageSource.h"
#include "include/effects/SkPaintImageFilter.h"

#include "include/c/sk_imagefilter.h"

#include "src/c/sk_types_priv.h"


// sk_imagefilter_croprect_t

sk_imagefilter_croprect_t* sk_imagefilter_croprect_new(void) {
    return (sk_imagefilter_croprect_t*) new SkImageFilter::CropRect();
}

sk_imagefilter_croprect_t* sk_imagefilter_croprect_new_with_rect(const sk_rect_t* rect, uint32_t flags) {
    return (sk_imagefilter_croprect_t*) new SkImageFilter::CropRect(*AsRect(rect), flags);
}

void sk_imagefilter_croprect_destructor(sk_imagefilter_croprect_t* cropRect) {
    delete AsImageFilterCropRect(cropRect);
}

// sk_imagefilter_t

void sk_imagefilter_unref(sk_imagefilter_t* cfilter) {
    SkSafeUnref(AsImageFilter(cfilter));
}

sk_imagefilter_t* sk_imagefilter_new_blur(float sigmaX, float sigmaY, sk_shader_tilemode_t tileMode, sk_imagefilter_t* input, const sk_imagefilter_croprect_t* cropRect) {
    return ToImageFilter(SkBlurImageFilter::Make(sigmaX, sigmaY, (SkTileMode)tileMode, sk_ref_sp(AsImageFilter(input)), AsImageFilterCropRect(cropRect)).release());
}

sk_imagefilter_t* sk_imagefilter_new_color_filter(sk_colorfilter_t* cf, sk_imagefilter_t* input, const sk_imagefilter_croprect_t* cropRect) {
    return ToImageFilter(SkColorFilterImageFilter::Make(sk_ref_sp(AsColorFilter(cf)), sk_ref_sp(AsImageFilter(input)), AsImageFilterCropRect(cropRect)).release());
}

sk_imagefilter_t* sk_imagefilter_new_compose(sk_imagefilter_t* outer, sk_imagefilter_t* inner) {
    return ToImageFilter(SkImageFilters::Compose(sk_ref_sp(AsImageFilter(outer)), sk_ref_sp(AsImageFilter(inner))).release());
}

sk_imagefilter_t* sk_imagefilter_new_drop_shadow(float dx, float dy, float sigmaX, float sigmaY, sk_color_t color, sk_imagefilter_t* input, const sk_imagefilter_croprect_t* cropRect) {
    return ToImageFilter(SkDropShadowImageFilter::Make(dx, dy, sigmaX, sigmaY, color, SkDropShadowImageFilter::ShadowMode::kDrawShadowAndForeground_ShadowMode, sk_ref_sp(AsImageFilter(input)), AsImageFilterCropRect(cropRect)).release());
}

sk_imagefilter_t* sk_imagefilter_new_drop_shadow_only(float dx, float dy, float sigmaX, float sigmaY, sk_color_t color, sk_imagefilter_t* input, const sk_imagefilter_croprect_t* cropRect) {
    return ToImageFilter(SkDropShadowImageFilter::Make(dx, dy, sigmaX, sigmaY, color, SkDropShadowImageFilter::ShadowMode::kDrawShadowOnly_ShadowMode, sk_ref_sp(AsImageFilter(input)), AsImageFilterCropRect(cropRect)).release());
}

sk_imagefilter_t* sk_imagefilter_new_matrix(const sk_matrix_t* cmatrix, sk_filter_quality_t cquality, sk_imagefilter_t* input) {
    return ToImageFilter(SkImageFilters::MatrixTransform(AsMatrix(cmatrix), (SkFilterQuality)cquality, sk_ref_sp(AsImageFilter(input))).release());
}

sk_imagefilter_t* sk_imagefilter_new_xfermode(sk_blendmode_t cmode, sk_imagefilter_t* background, sk_imagefilter_t* foreground, const sk_imagefilter_croprect_t* cropRect) {
    return ToImageFilter(SkXfermodeImageFilter::Make((SkBlendMode)cmode, sk_ref_sp(AsImageFilter(background)), sk_ref_sp(AsImageFilter(foreground)), AsImageFilterCropRect(cropRect)).release());
}
