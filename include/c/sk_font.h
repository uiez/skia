/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk_font_DEFINED
#define sk_font_DEFINED

#include "include/c/sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

// sk_font_t

SK_C_API sk_font_t* sk_font_new_with_values(sk_typeface_t* typeface, float size, float scaleX, float skewX);
SK_C_API void sk_font_delete(sk_font_t* font);
SK_C_API void sk_font_set_force_auto_hinting(sk_font_t* font, bool value);
SK_C_API bool sk_font_is_subpixel(const sk_font_t* font);
SK_C_API void sk_font_set_subpixel(sk_font_t* font, bool value);
SK_C_API void sk_font_set_embolden(sk_font_t* font, bool value);
SK_C_API void sk_font_set_edging(sk_font_t* font, sk_font_edging_t value);
SK_C_API void sk_font_set_hinting(sk_font_t* font, sk_font_hinting_t value);
SK_C_API sk_typeface_t* sk_font_get_typeface(const sk_font_t* font);
SK_C_API float sk_font_get_size(const sk_font_t* font);
SK_C_API uint16_t sk_font_unichar_to_glyph(const sk_font_t* font, int32_t uni);
SK_C_API void sk_font_unichars_to_glyphs(const sk_font_t* font, const int32_t uni[], int count, uint16_t glyphs[]);
SK_C_API void sk_font_get_widths_bounds(const sk_font_t* font, const uint16_t glyphs[], int count, float widths[], sk_rect_t bounds[], const sk_paint_t* paint);
SK_C_API float sk_font_get_metrics(const sk_font_t* font, sk_fontmetrics_t* metrics);

SK_C_PLUS_PLUS_END_GUARD

#endif
