/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk_paint_DEFINED
#define sk_paint_DEFINED

#include "include/c/sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API sk_paint_t* sk_paint_new(void);
SK_C_API void sk_paint_delete(sk_paint_t*);
SK_C_API void sk_paint_set_antialias(sk_paint_t*, bool);
SK_C_API void sk_paint_set_color(sk_paint_t*, sk_color_t);
SK_C_API void sk_paint_set_style(sk_paint_t*, sk_paint_style_t);
SK_C_API void sk_paint_set_stroke_width(sk_paint_t*, float width);
SK_C_API void sk_paint_set_stroke_miter(sk_paint_t*, float miter);
SK_C_API void sk_paint_set_stroke_cap(sk_paint_t*, sk_stroke_cap_t);
SK_C_API void sk_paint_set_stroke_join(sk_paint_t*, sk_stroke_join_t);
SK_C_API void sk_paint_set_shader(sk_paint_t*, sk_shader_t*);
SK_C_API void sk_paint_set_maskfilter(sk_paint_t*, sk_maskfilter_t*);
SK_C_API void sk_paint_set_blendmode(sk_paint_t*, sk_blendmode_t);
SK_C_API bool sk_paint_is_dither(const sk_paint_t*);
SK_C_API void sk_paint_set_dither(sk_paint_t*, bool);
SK_C_API void sk_paint_set_colorfilter(sk_paint_t*, sk_colorfilter_t*);
SK_C_API void sk_paint_set_imagefilter(sk_paint_t*, sk_imagefilter_t*);
SK_C_API void sk_paint_set_filter_quality(sk_paint_t*, sk_filter_quality_t);

SK_C_PLUS_PLUS_END_GUARD

#endif
