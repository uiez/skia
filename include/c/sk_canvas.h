/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk_canvas_DEFINED
#define sk_canvas_DEFINED

#include "include/c/sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API void sk_canvas_destroy(sk_canvas_t*);
SK_C_API int sk_canvas_save(sk_canvas_t*);
SK_C_API int sk_canvas_save_layer(sk_canvas_t*, const sk_rect_t*, const sk_paint_t*);
SK_C_API int sk_canvas_save_layer_rec(sk_canvas_t*, const sk_save_layer_rec_t*);
SK_C_API void sk_canvas_restore(sk_canvas_t*);
SK_C_API void sk_canvas_translate(sk_canvas_t*, float dx, float dy);
SK_C_API void sk_canvas_scale(sk_canvas_t*, float sx, float sy);
SK_C_API void sk_canvas_rotate_radians(sk_canvas_t*, float radians);
SK_C_API void sk_canvas_skew(sk_canvas_t*, float sx, float sy);
SK_C_API void sk_canvas_concat(sk_canvas_t*, const sk_matrix_t*);
SK_C_API void sk_canvas_draw_paint(sk_canvas_t*, const sk_paint_t*);
SK_C_API void sk_canvas_draw_rect(sk_canvas_t*, const sk_rect_t*, const sk_paint_t*);
SK_C_API void sk_canvas_draw_rrect(sk_canvas_t*, const sk_rrect_t*, const sk_paint_t*);
SK_C_API void sk_canvas_draw_path(sk_canvas_t*, const sk_path_t*, const sk_paint_t*);
SK_C_API void sk_canvas_clear(sk_canvas_t*, sk_color_t);
SK_C_API void sk_canvas_draw_text_blob (sk_canvas_t*, sk_textblob_t* text, float x, float y, const sk_paint_t* paint);
SK_C_API void sk_canvas_draw_immutable_bitmap_rect(sk_canvas_t* ccanvas, const sk_bitmap_t* bitmap, const sk_rect_t* dst, const sk_paint_t* paint);
SK_C_API void sk_canvas_set_matrix(sk_canvas_t* ccanvas, const sk_matrix_t* matrix);
SK_C_API void sk_canvas_get_total_matrix(sk_canvas_t* ccanvas, sk_matrix_t* matrix);
SK_C_API void sk_canvas_clip_rect_with_operation(sk_canvas_t* t, const sk_rect_t* crect, sk_clipop_t op, bool doAA);
SK_C_API void sk_canvas_clip_path_with_operation(sk_canvas_t* t, const sk_path_t* crect, sk_clipop_t op, bool doAA);
SK_C_API void sk_canvas_clip_rrect_with_operation(sk_canvas_t* t, const sk_rrect_t* crect, sk_clipop_t op, bool doAA);
SK_C_API void sk_canvas_flush(sk_canvas_t* ccanvas);

SK_C_PLUS_PLUS_END_GUARD

#endif
