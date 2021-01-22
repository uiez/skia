/*
 * Copyright 2014 Google Inc.
 * Copyright 2016 Xamarin Inc.
 * Copyright 2018 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk_rrect_DEFINED
#define sk_rrect_DEFINED

#include "include/c/sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API sk_rrect_t* sk_rrect_new(void);
SK_C_API void sk_rrect_delete(const sk_rrect_t* rrect);
SK_C_API void sk_rrect_set_rect_radii(sk_rrect_t* rrect, const sk_rect_t* rect, const sk_vector_t* radii);

SK_C_PLUS_PLUS_END_GUARD

#endif
