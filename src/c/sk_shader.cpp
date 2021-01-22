/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/core/SkShader.h"
#include "include/effects/SkGradientShader.h"

#include "include/c/sk_shader.h"

#include "src/c/sk_types_priv.h"

// SkShader

void sk_shader_ref(sk_shader_t* shader) {
    SkSafeRef(AsShader(shader));
}

void sk_shader_unref(sk_shader_t* shader) {
    SkSafeUnref(AsShader(shader));
}

// SkShaders

sk_shader_t* sk_shader_new_blend(sk_blendmode_t mode, const sk_shader_t* dst, const sk_shader_t* src) {
    return ToShader(SkShaders::Blend((SkBlendMode)mode, sk_ref_sp(AsShader(dst)), sk_ref_sp(AsShader(src))).release());
}

sk_shader_t* sk_shader_new_lerp(float t, const sk_shader_t* dst, const sk_shader_t* src) {
    return ToShader(SkShaders::Lerp(t, sk_ref_sp(AsShader(dst)), sk_ref_sp(AsShader(src))).release());
}

// SkGradientShader

sk_shader_t* sk_shader_new_linear_gradient(const sk_point_t points[2], const sk_color_t colors[], const float colorPos[], int colorCount, sk_shader_tilemode_t tileMode, const sk_matrix_t* localMatrix) {
    SkMatrix m;
    if (localMatrix)
        m = AsMatrix(localMatrix);
    return ToShader(SkGradientShader::MakeLinear(AsPoint(points), colors, colorPos, colorCount, (SkTileMode)tileMode, 0, localMatrix ? &m : nullptr).release());
}

sk_shader_t* sk_shader_new_radial_gradient(const sk_point_t* center, float radius, const sk_color_t colors[], const float colorPos[], int colorCount, sk_shader_tilemode_t tileMode, const sk_matrix_t* localMatrix) {
    SkMatrix m;
    if (localMatrix)
        m = AsMatrix(localMatrix);
    return ToShader(SkGradientShader::MakeRadial(*AsPoint(center), (SkScalar)radius, colors, colorPos, colorCount, (SkTileMode)tileMode, 0, localMatrix ? &m : nullptr).release());
}

sk_shader_t* sk_shader_new_sweep_gradient(const sk_point_t* center, const sk_color_t colors[], const float colorPos[], int colorCount, sk_shader_tilemode_t tileMode, float startAngle, float endAngle, const sk_matrix_t* localMatrix) {
    SkMatrix m;
    if (localMatrix)
        m = AsMatrix(localMatrix);
    return ToShader(SkGradientShader::MakeSweep(center->x, center->y, colors, colorPos, colorCount, (SkTileMode)tileMode, startAngle, endAngle, 0, localMatrix ? &m : nullptr).release());
}
