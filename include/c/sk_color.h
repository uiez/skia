/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk_color_DEFINED
#define sk_color_DEFINED

#include "include/c/sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API sk_colortype_t sk_colortype_get_default_8888(void);

SK_C_API sk_color_t sk_color4f_to_color(const sk_color4f_t* color4f);
SK_C_API void sk_color4f_from_color(sk_color_t color, sk_color4f_t* color4f);

SK_C_PLUS_PLUS_END_GUARD

#endif
