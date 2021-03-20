/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk_bitmap_DEFINED
#define sk_bitmap_DEFINED

#include "include/c/sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API void sk_bitmap_destructor(sk_bitmap_t* cbitmap);
SK_C_API sk_bitmap_t* sk_bitmap_new(void);
SK_C_API void sk_bitmap_set_immutable(sk_bitmap_t* cbitmap);
SK_C_API bool sk_bitmap_is_immutable(sk_bitmap_t* cbitmap);
SK_C_API void sk_bitmap_get_info(sk_bitmap_t* cbitmap, sk_imageinfo_t* info);
SK_C_API void* sk_bitmap_get_pixels(sk_bitmap_t* cbitmap, size_t* length);
SK_C_API size_t sk_bitmap_get_byte_count(sk_bitmap_t* cbitmap);
SK_C_API bool sk_bitmap_try_alloc_pixels(sk_bitmap_t* cbitmap, const sk_imageinfo_t* requestedInfo, size_t rowBytes);
SK_C_API void sk_bitmap_notify_pixels_changed(sk_bitmap_t* cbitmap);
SK_C_API void sk_bitmap_swap(sk_bitmap_t* cbitmap, sk_bitmap_t* cother);
SK_C_API sk_shader_t* sk_bitmap_make_shader(sk_bitmap_t* cbitmap, sk_shader_tilemode_t tmx, sk_shader_tilemode_t tmy, const sk_matrix_t* cmatrix);

SK_C_PLUS_PLUS_END_GUARD

#endif
