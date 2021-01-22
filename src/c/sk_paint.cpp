/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/core/SkColorFilter.h"
#include "include/core/SkMaskFilter.h"
#include "include/core/SkPaint.h"
#include "include/core/SkShader.h"

#include "include/c/sk_paint.h"

#include "src/c/sk_types_priv.h"

sk_paint_t* sk_paint_new(void) {
    return ToPaint(new SkPaint());
}

void sk_paint_delete(sk_paint_t* cpaint) { delete AsPaint(cpaint); }

void sk_paint_set_antialias(sk_paint_t* cpaint, bool aa) {
    AsPaint(cpaint)->setAntiAlias(aa);
}

void sk_paint_set_color(sk_paint_t* cpaint, sk_color_t c) {
    AsPaint(cpaint)->setColor(c);
}

void sk_paint_set_shader(sk_paint_t* cpaint, sk_shader_t* cshader) {
    AsPaint(cpaint)->setShader(sk_ref_sp(AsShader(cshader)));
}

void sk_paint_set_maskfilter(sk_paint_t* cpaint, sk_maskfilter_t* cfilter) {
    AsPaint(cpaint)->setMaskFilter(sk_ref_sp(AsMaskFilter(cfilter)));
}

void sk_paint_set_style(sk_paint_t* cpaint, sk_paint_style_t style) {
    AsPaint(cpaint)->setStyle((SkPaint::Style)style);
}

void sk_paint_set_stroke_width(sk_paint_t* cpaint, float width) {
    AsPaint(cpaint)->setStrokeWidth(width);
}

void sk_paint_set_stroke_miter(sk_paint_t* cpaint, float miter) {
    AsPaint(cpaint)->setStrokeMiter(miter);
}

void sk_paint_set_stroke_cap(sk_paint_t* cpaint, sk_stroke_cap_t ccap) {
    AsPaint(cpaint)->setStrokeCap((SkPaint::Cap)ccap);
}

void sk_paint_set_stroke_join(sk_paint_t* cpaint, sk_stroke_join_t cjoin) {
    AsPaint(cpaint)->setStrokeJoin((SkPaint::Join)cjoin);
}

void sk_paint_set_blendmode(sk_paint_t* paint, sk_blendmode_t mode) {
    AsPaint(paint)->setBlendMode((SkBlendMode)mode);
}

bool sk_paint_is_dither(const sk_paint_t* cpaint) {
    return AsPaint(cpaint)->isDither();
}

void sk_paint_set_dither(sk_paint_t* cpaint, bool isdither) {
    AsPaint(cpaint)->setDither(isdither);
}

void sk_paint_set_colorfilter(sk_paint_t* cpaint, sk_colorfilter_t* cfilter) {
    AsPaint(cpaint)->setColorFilter(sk_ref_sp(AsColorFilter(cfilter)));
}

void sk_paint_set_imagefilter(sk_paint_t* cpaint, sk_imagefilter_t* cfilter) {
    AsPaint(cpaint)->setImageFilter(sk_ref_sp(AsImageFilter(cfilter)));
}

void sk_paint_set_filter_quality(sk_paint_t* cpaint, sk_filter_quality_t filterQuality) {
    AsPaint(cpaint)->setFilterQuality((SkFilterQuality)filterQuality);
}
