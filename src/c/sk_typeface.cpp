/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/core/SkFontMgr.h"
#include "include/core/SkFontStyle.h"
#include "include/core/SkTypeface.h"
#include "include/core/SkFont.h"
#include "include/ports/SkTypeface_mac.h"

#include <memory>

#include "include/c/sk_typeface.h"

#include "src/c/sk_types_priv.h"

// typeface

void sk_typeface_unref(sk_typeface_t* typeface) {
    SkSafeUnref(AsTypeface(typeface));
}
sk_font_id_t sk_typeface_get_unique_id(const sk_typeface_t* typeface) {
    return (sk_font_id_t)AsTypeface(typeface)->uniqueID();
}
sk_fontstyle_t* sk_typeface_get_fontstyle(const sk_typeface_t* typeface) {
    SkFontStyle fs = AsTypeface(typeface)->fontStyle();
    return ToFontStyle(new SkFontStyle(fs.weight(), fs.width(), fs.slant()));
}

sk_typeface_t* sk_typeface_create_default(void) {
    return ToTypeface(SkTypeface::MakeDefault().release());
}

sk_typeface_t* sk_typeface_create_from_file(const char* path, int index) {
    return ToTypeface(SkTypeface::MakeFromFile(path, index).release());
}

sk_typeface_t* sk_typeface_create_from_data(sk_data_t* data, int index) {
    return ToTypeface(SkTypeface::MakeFromData(sk_ref_sp(AsData(data)), index).release());
}

void sk_typeface_unichars_to_glyphs(const sk_typeface_t* typeface, const int32_t unichars[], int count, uint16_t glyphs[]) {
    AsTypeface(typeface)->unicharsToGlyphs(unichars, count, glyphs);
}

uint16_t sk_typeface_unichar_to_glyph(const sk_typeface_t* typeface, const int32_t unichar) {
    return AsTypeface(typeface)->unicharToGlyph(unichar);
}

size_t sk_typeface_get_table_size(const sk_typeface_t* typeface, sk_font_table_tag_t tag) {
    return AsTypeface(typeface)->getTableSize(tag);
}

size_t sk_typeface_get_table_data(const sk_typeface_t* typeface, sk_font_table_tag_t tag, size_t offset, size_t length, void* data) {
    return AsTypeface(typeface)->getTableData(tag, offset, length, data);
}

sk_string_t* sk_typeface_get_family_name(const sk_typeface_t* typeface) {
    SkString* family_name = new SkString();
    AsTypeface(typeface)->getFamilyName(family_name);
    return ToString(family_name);
}

void *sk_typeface_get_native(const sk_typeface_t* typeface, sk_typeface_native_type_t* type) {
    SkTypeface::NativeType nativeType = SkTypeface::NativeType::Unknown;
    void *native = AsTypeface(typeface)->getNativeTypeface(&nativeType);
    if (type){
        *type = (sk_typeface_native_type_t)nativeType;
    }
    return native;
}

// font manager

sk_fontmgr_t* sk_fontmgr_ref_default(void) {
    return ToFontMgr(SkFontMgr::RefDefault().release());
}

void sk_fontmgr_unref(sk_fontmgr_t* fontmgr) {
    AsFontMgr(fontmgr)->unref();
}

int sk_fontmgr_count_families(sk_fontmgr_t* fontmgr) {
    return AsFontMgr(fontmgr)->countFamilies();
}

void sk_fontmgr_get_family_name(sk_fontmgr_t* fontmgr, int index, sk_string_t* familyName) {
    AsFontMgr(fontmgr)->getFamilyName(index, AsString(familyName));
}

sk_typeface_t* sk_fontmgr_match_family_style(sk_fontmgr_t* fontmgr, const char* familyName, sk_fontstyle_t* style) {
    return ToTypeface(AsFontMgr(fontmgr)->matchFamilyStyle(familyName, *AsFontStyle(style)));
}

sk_typeface_t* sk_fontmgr_match_family_style_character(sk_fontmgr_t* fontmgr, const char* familyName, sk_fontstyle_t* style, const char** bcp47, int bcp47Count, int32_t character) {
    return ToTypeface(AsFontMgr(fontmgr)->matchFamilyStyleCharacter(familyName, *AsFontStyle(style), bcp47, bcp47Count, character));
}

// font style

sk_fontstyle_t* sk_fontstyle_new(int weight, int width, sk_font_style_slant_t slant) {
    return ToFontStyle(new SkFontStyle(weight, width,(SkFontStyle::Slant)slant));
}

void sk_fontstyle_delete(sk_fontstyle_t* fs) {
    delete AsFontStyle(fs);
}

int sk_fontstyle_get_weight(const sk_fontstyle_t* fs) {
    return AsFontStyle(fs)->weight();
}

int sk_fontstyle_get_width(const sk_fontstyle_t* fs) {
    return AsFontStyle(fs)->width();
}

sk_font_style_slant_t sk_fontstyle_get_slant(const sk_fontstyle_t* fs) {
    return (sk_font_style_slant_t)AsFontStyle(fs)->slant();
}

