/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/core/SkMatrix.h"
#include "include/core/SkMatrix44.h"
#include "include/utils/SkCamera.h"

#include "include/c/sk_matrix.h"

#include "src/c/sk_types_priv.h"

bool sk_matrix_try_invert(sk_matrix_t *matrix, sk_matrix_t *result) {
    SkMatrix inverse;
    if(AsMatrix(matrix).invert(&inverse)){
        *result = ToMatrix(&inverse);
        return true;
    }
    return false;
}

void sk_matrix_concat(sk_matrix_t *matrix, sk_matrix_t *first, sk_matrix_t *second) {
    SkMatrix m = AsMatrix(matrix);
    m.setConcat(AsMatrix(first), AsMatrix(second));
    *matrix = ToMatrix(&m);
}

void sk_matrix_pre_concat(sk_matrix_t *target, sk_matrix_t *matrix) {
    SkMatrix m = AsMatrix(target);
    m.preConcat(AsMatrix(matrix));
    *target = ToMatrix(&m);
}

void sk_matrix_post_concat(sk_matrix_t *target, sk_matrix_t *matrix) {
    SkMatrix m = AsMatrix(target);
    m.postConcat(AsMatrix(matrix));
    *target = ToMatrix(&m);
}
