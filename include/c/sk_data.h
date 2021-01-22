/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk_data_DEFINED
#define sk_data_DEFINED

#include "include/c/sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API void sk_data_ref(const sk_data_t*);
SK_C_API void sk_data_unref(const sk_data_t*);
SK_C_API size_t sk_data_get_size(const sk_data_t*);
SK_C_API const void* sk_data_get_data(const sk_data_t*);
SK_C_API sk_data_t* sk_data_new_uninitialized(size_t size);

SK_C_PLUS_PLUS_END_GUARD

#endif
