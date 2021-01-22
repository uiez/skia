/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk_matrix_DEFINED
#define sk_matrix_DEFINED

#include "include/c/sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API bool sk_matrix_try_invert (sk_matrix_t *matrix, sk_matrix_t *result);
SK_C_API void sk_matrix_concat (sk_matrix_t *result, sk_matrix_t *first, sk_matrix_t *second);
SK_C_API void sk_matrix_pre_concat (sk_matrix_t *result, sk_matrix_t *matrix);
SK_C_API void sk_matrix_post_concat (sk_matrix_t *result, sk_matrix_t *matrix);

SK_C_PLUS_PLUS_END_GUARD

#endif
