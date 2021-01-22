/*
 * Copyright 2014 Google Inc.
 * Copyright 2016 Xamarin Inc.
 * Copyright 2018 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/core/SkRRect.h"

#include "include/c/sk_rrect.h"

#include "src/c/sk_types_priv.h"


sk_rrect_t* sk_rrect_new(void) {
    return ToRRect(new SkRRect());
}

void sk_rrect_delete(const sk_rrect_t* rrect) {
  delete AsRRect(rrect);
}

void sk_rrect_set_rect_radii(sk_rrect_t* rrect, const sk_rect_t* rect, const sk_vector_t* radii) {
    AsRRect(rrect)->setRectRadii(*AsRect(rect), AsPoint(radii));
}
