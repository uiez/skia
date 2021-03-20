/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk_imagefilter_DEFINED
#define sk_imagefilter_DEFINED

#include "include/c/sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

// sk_imagefilter_t

SK_C_API void sk_imagefilter_unref(sk_imagefilter_t*);

SK_C_API sk_imagefilter_t* sk_imagefilter_new_blur(float sigmaX, float sigmaY, sk_shader_tilemode_t tileMode, sk_imagefilter_t* input, const sk_rect_t* cropRect);
SK_C_API sk_imagefilter_t* sk_imagefilter_new_color_filter(sk_colorfilter_t* cf, sk_imagefilter_t* input, const sk_rect_t* cropRect);
SK_C_API sk_imagefilter_t* sk_imagefilter_new_compose(sk_imagefilter_t* outer, sk_imagefilter_t* inner);
SK_C_API sk_imagefilter_t* sk_imagefilter_new_drop_shadow(float dx, float dy, float sigmaX, float sigmaY, sk_color_t color, sk_imagefilter_t* input, const sk_rect_t* cropRect);
SK_C_API sk_imagefilter_t* sk_imagefilter_new_drop_shadow_only(float dx, float dy, float sigmaX, float sigmaY, sk_color_t color, sk_imagefilter_t* input, const sk_rect_t* cropRect);
SK_C_API sk_imagefilter_t* sk_imagefilter_new_matrix(const sk_matrix_t* matrix, sk_imagefilter_t* input);
SK_C_API sk_imagefilter_t* sk_imagefilter_new_blendmode(sk_blendmode_t mode, sk_imagefilter_t* background, sk_imagefilter_t* foreground, const sk_rect_t* cropRect);


SK_C_PLUS_PLUS_END_GUARD

#endif
