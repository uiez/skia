/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/core/SkFont.h"
#include "include/core/SkTypeface.h"

#include "include/c/sk_font.h"

#include "src/c/sk_types_priv.h"

// sk_font_t

sk_font_t* sk_font_new_with_values(sk_typeface_t* typeface, float size, float scaleX, float skewX) {
    return ToFont(new SkFont(sk_ref_sp(AsTypeface(typeface)), size, scaleX, skewX));
}

void sk_font_delete(sk_font_t* font) {
    delete AsFont(font);
}

bool sk_font_is_subpixel(const sk_font_t* font) {
    return AsFont(font)->isSubpixel();
}

void sk_font_set_subpixel(sk_font_t* font, bool value) {
    AsFont(font)->setSubpixel(value);
}

void sk_font_set_embolden(sk_font_t* font, bool value) {
    AsFont(font)->setEmbolden(value);
}

void sk_font_set_edging(sk_font_t* font, sk_font_edging_t value) {
    AsFont(font)->setEdging((SkFont::Edging)value);
}

void sk_font_set_hinting(sk_font_t* font, sk_font_hinting_t value) {
    AsFont(font)->setHinting((SkFontHinting)value);
}

sk_typeface_t* sk_font_get_typeface(const sk_font_t* font) {
    return ToTypeface(AsFont(font)->refTypeface().release());
}

float sk_font_get_size(const sk_font_t* font) {
    return AsFont(font)->getSize();
}

uint16_t sk_font_unichar_to_glyph(const sk_font_t* font, int32_t uni) {
    return AsFont(font)->unicharToGlyph(uni);
}

void sk_font_unichars_to_glyphs(const sk_font_t* font, const int32_t uni[], int count, uint16_t glyphs[]) {
    AsFont(font)->unicharsToGlyphs(uni, count, glyphs);
}

void sk_font_get_widths_bounds(const sk_font_t* font, const uint16_t glyphs[], int count, float widths[], sk_rect_t bounds[], const sk_paint_t* paint) {
    AsFont(font)->getWidthsBounds(glyphs, count, widths, AsRect(bounds), AsPaint(paint));
}

float sk_font_get_metrics(const sk_font_t* font, sk_fontmetrics_t* metrics) {
    return AsFont(font)->getMetrics(AsFontMetrics(metrics));
}
