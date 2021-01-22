/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/core/SkBitmap.h"
#include "include/core/SkImageInfo.h"

#include "include/c/sk_bitmap.h"

#include "src/c/sk_types_priv.h"

void sk_bitmap_destructor(sk_bitmap_t* cbitmap) {
    delete AsBitmap(cbitmap);
}

sk_bitmap_t* sk_bitmap_new(void) {
    return ToBitmap(new SkBitmap());
}

void sk_bitmap_get_info(sk_bitmap_t* cbitmap, sk_imageinfo_t* info) {
    *info = ToImageInfo(AsBitmap(cbitmap)->info());
}

void* sk_bitmap_get_pixels(sk_bitmap_t* cbitmap, size_t* length) {
    SkBitmap* bmp = AsBitmap(cbitmap);
    *length = bmp->computeByteSize();
    return bmp->getPixels();
}

size_t sk_bitmap_get_byte_count(sk_bitmap_t* cbitmap) {
    return AsBitmap(cbitmap)->computeByteSize();
}

bool sk_bitmap_try_alloc_pixels(sk_bitmap_t* cbitmap, const sk_imageinfo_t* requestedInfo, size_t rowBytes) {
    return AsBitmap(cbitmap)->tryAllocPixels(AsImageInfo(requestedInfo), rowBytes);
}

void sk_bitmap_notify_pixels_changed(sk_bitmap_t* cbitmap) {
    AsBitmap(cbitmap)->notifyPixelsChanged();
}
