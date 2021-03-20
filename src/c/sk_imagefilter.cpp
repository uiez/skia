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
#include "include/core/SkSamplingOptions.h"
#include "include/effects/SkImageFilters.h"

#include "include/c/sk_imagefilter.h"

#include "src/c/sk_types_priv.h"


// sk_imagefilter_t

void sk_imagefilter_unref(sk_imagefilter_t* cfilter) {
    SkSafeUnref(AsImageFilter(cfilter));
}

sk_imagefilter_t* sk_imagefilter_new_blur(float sigmaX, float sigmaY, sk_shader_tilemode_t tileMode, sk_imagefilter_t* input, const sk_rect_t* cropRect) {
    return ToImageFilter(SkImageFilters::Blur(sigmaX, sigmaY, (SkTileMode)tileMode, sk_ref_sp(AsImageFilter(input)), AsImageFiltersCropRect(cropRect)).release());
}

sk_imagefilter_t* sk_imagefilter_new_color_filter(sk_colorfilter_t* cf, sk_imagefilter_t* input, const sk_rect_t* cropRect) {
    return ToImageFilter(SkImageFilters::ColorFilter(sk_ref_sp(AsColorFilter(cf)), sk_ref_sp(AsImageFilter(input)), AsImageFiltersCropRect(cropRect)).release());
}

sk_imagefilter_t* sk_imagefilter_new_compose(sk_imagefilter_t* outer, sk_imagefilter_t* inner) {
    return ToImageFilter(SkImageFilters::Compose(sk_ref_sp(AsImageFilter(outer)), sk_ref_sp(AsImageFilter(inner))).release());
}

sk_imagefilter_t* sk_imagefilter_new_drop_shadow(float dx, float dy, float sigmaX, float sigmaY, sk_color_t color, sk_imagefilter_t* input, const sk_rect_t* cropRect) {
    return ToImageFilter(SkImageFilters::DropShadow(dx, dy, sigmaX, sigmaY, color,  sk_ref_sp(AsImageFilter(input)), AsImageFiltersCropRect(cropRect)).release());
}

sk_imagefilter_t* sk_imagefilter_new_drop_shadow_only(float dx, float dy, float sigmaX, float sigmaY, sk_color_t color, sk_imagefilter_t* input, const sk_rect_t* cropRect) {
    return ToImageFilter(SkImageFilters::DropShadowOnly(dx, dy, sigmaX, sigmaY, color, sk_ref_sp(AsImageFilter(input)), AsImageFiltersCropRect(cropRect)).release());
}

sk_imagefilter_t* sk_imagefilter_new_matrix(const sk_matrix_t* cmatrix, sk_imagefilter_t* input) {
    return ToImageFilter(SkImageFilters::MatrixTransform(AsMatrix(cmatrix), SkSamplingOptions(), sk_ref_sp(AsImageFilter(input))).release());
}

sk_imagefilter_t* sk_imagefilter_new_blendmode(sk_blendmode_t cmode, sk_imagefilter_t* background, sk_imagefilter_t* foreground, const sk_rect_t* cropRect) {
    return ToImageFilter(SkImageFilters::Blend((SkBlendMode)cmode, sk_ref_sp(AsImageFilter(background)), sk_ref_sp(AsImageFilter(foreground)), AsImageFiltersCropRect(cropRect)).release());
}
