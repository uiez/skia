/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/c/sk_color.h"

#include "src/c/sk_types_priv.h"


// sk_color4f_t

sk_color_t sk_color4f_to_color(const sk_color4f_t* color4f) {
    return AsColor4f(color4f)->toSkColor();
}

void sk_color4f_from_color(sk_color_t color, sk_color4f_t* color4f) {
    *color4f = ToColor4f(SkColor4f::FromColor(color));
}

// color type

sk_colortype_t sk_colortype_get_default_8888(void) {
    return (sk_colortype_t)SkColorType::kN32_SkColorType;
}
