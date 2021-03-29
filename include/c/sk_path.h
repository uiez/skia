/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk_path_DEFINED
#define sk_path_DEFINED

#include "include/c/sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

/* Path */
SK_C_API sk_path_t* sk_path_new(void);
SK_C_API void sk_path_delete(sk_path_t*);
SK_C_API void sk_path_move_to(sk_path_t*, float x, float y);
SK_C_API void sk_path_line_to(sk_path_t*, float x, float y);
SK_C_API void sk_path_quad_to(sk_path_t*, float x0, float y0, float x1, float y1);
SK_C_API void sk_path_conic_to(sk_path_t*, float x0, float y0, float x1, float y1, float w);
SK_C_API void sk_path_cubic_to(sk_path_t*, float x0, float y0, float x1, float y1, float x2, float y2);
SK_C_API void sk_path_arc_to(sk_path_t*, float rx, float ry, float xAxisRotate, sk_path_arc_size_t largeArc, sk_path_direction_t sweep, float x, float y);
SK_C_API void sk_path_arc_to_with_oval(sk_path_t*, const sk_rect_t* oval, float startAngle, float sweepAngle, bool forceMoveTo);
SK_C_API void sk_path_arc_to_with_points(sk_path_t*, float x1, float y1, float x2, float y2, float radius);
SK_C_API void sk_path_close(sk_path_t*);
SK_C_API void sk_path_add_rect(sk_path_t*, const sk_rect_t*, sk_path_direction_t);
SK_C_API void sk_path_add_rrect(sk_path_t*, const sk_rrect_t*, sk_path_direction_t);
SK_C_API void sk_path_add_oval(sk_path_t*, const sk_rect_t*, sk_path_direction_t);
SK_C_API void sk_path_add_circle(sk_path_t*, float x, float y, float radius, sk_path_direction_t dir);
SK_C_API void sk_path_get_bounds(const sk_path_t*, sk_rect_t*);
SK_C_API void sk_path_compute_tight_bounds(const sk_path_t*, sk_rect_t*);
SK_C_API void sk_path_add_arc(sk_path_t* cpath, const sk_rect_t* crect, float startAngle, float sweepAngle);
SK_C_API void sk_path_set_filltype(sk_path_t*, sk_path_filltype_t);
SK_C_API void sk_path_add_path_offset  (sk_path_t* cpath, sk_path_t* other, float dx, float dy, sk_path_add_mode_t add_mode);
SK_C_API void sk_path_reset(sk_path_t* cpath);
SK_C_API void sk_path_rewind(sk_path_t* cpath);
SK_C_API bool sk_path_contains (const sk_path_t* cpath, float x, float y);

SK_C_PLUS_PLUS_END_GUARD

#endif
