/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/core/SkCanvas.h"
#include "include/c/sk_canvas.h"

#include "src/c/sk_types_priv.h"

void sk_canvas_destroy(sk_canvas_t* ccanvas) {
    delete AsCanvas(ccanvas);
}

void sk_canvas_clear(sk_canvas_t* ccanvas, sk_color_t color) {
    AsCanvas(ccanvas)->clear(color);
}

void sk_canvas_draw_immutable_bitmap_rect(sk_canvas_t* ccanvas, const sk_bitmap_t* cbitmap, const sk_rect_t* cdstR, const sk_paint_t* cpaint) {
    sk_sp<SkImage> img = AsBitmap(cbitmap)->asImage();
    AsCanvas(ccanvas)->drawImageRect(img, *AsRect(cdstR), SkSamplingOptions(), AsPaint(cpaint));
}

void sk_canvas_set_matrix(sk_canvas_t* ccanvas, const sk_matrix_t* cmatrix) {
    AsCanvas(ccanvas)->setMatrix(AsMatrix(cmatrix));
}

void sk_canvas_get_total_matrix(sk_canvas_t* ccanvas, sk_matrix_t* cmatrix) {
    *cmatrix = ToMatrix(AsCanvas(ccanvas)->getTotalMatrix());
}

void sk_canvas_clip_rect_with_operation(sk_canvas_t* ccanvas, const sk_rect_t* crect, sk_clipop_t op, bool doAA) {
    AsCanvas(ccanvas)->clipRect(*AsRect(crect), (SkClipOp)op, doAA);
}

void sk_canvas_clip_path_with_operation(sk_canvas_t* ccanvas, const sk_path_t* cpath, sk_clipop_t op, bool doAA) {
    AsCanvas(ccanvas)->clipPath(*AsPath(cpath), (SkClipOp)op, doAA);
}

void sk_canvas_clip_rrect_with_operation(sk_canvas_t* ccanvas, const sk_rrect_t* crect, sk_clipop_t op, bool doAA) {
    AsCanvas(ccanvas)->clipRRect(*AsRRect(crect), (SkClipOp)op, doAA);
}

int sk_canvas_save(sk_canvas_t* ccanvas) {
    return AsCanvas(ccanvas)->save();
}

int sk_canvas_save_layer(sk_canvas_t* ccanvas, const sk_rect_t* crect, const sk_paint_t* cpaint) {
    return AsCanvas(ccanvas)->saveLayer(AsRect(crect), AsPaint(cpaint));
}

int sk_canvas_save_layer_rec(sk_canvas_t* ccanvas, const sk_save_layer_rec_t* crec) {
    SkCanvas::SaveLayerRec rec;
    rec.fBounds = AsRect(&crec->bounds);
    rec.fPaint = AsPaint(crec->paint);
    rec.fBackdrop = AsImageFilter(crec->backdrop);
    rec.fSaveLayerFlags = crec->flags;
    return AsCanvas(ccanvas)->saveLayer(rec);
}

void sk_canvas_restore(sk_canvas_t* ccanvas) {
    AsCanvas(ccanvas)->restore();
}

void sk_canvas_translate(sk_canvas_t* ccanvas, float dx, float dy) {
    AsCanvas(ccanvas)->translate(dx, dy);
}

void sk_canvas_scale(sk_canvas_t* ccanvas, float sx, float sy) {
    AsCanvas(ccanvas)->scale(sx, sy);
}

void sk_canvas_rotate_radians(sk_canvas_t* ccanvas, float radians) {
    AsCanvas(ccanvas)->rotate(SkRadiansToDegrees(radians));
}

void sk_canvas_skew(sk_canvas_t* ccanvas, float sx, float sy) {
    AsCanvas(ccanvas)->skew(sx, sy);
}

void sk_canvas_concat(sk_canvas_t* ccanvas, const sk_matrix_t* cmatrix) {
    AsCanvas(ccanvas)->concat(AsMatrix(cmatrix));
}

void sk_canvas_draw_paint(sk_canvas_t* ccanvas, const sk_paint_t* cpaint) {
    AsCanvas(ccanvas)->drawPaint(*AsPaint(cpaint));
}

void sk_canvas_draw_rect(sk_canvas_t* ccanvas, const sk_rect_t* crect, const sk_paint_t* cpaint) {
    AsCanvas(ccanvas)->drawRect(*AsRect(crect), *AsPaint(cpaint));
}

void sk_canvas_draw_rrect(sk_canvas_t* ccanvas, const sk_rrect_t* crect, const sk_paint_t* cpaint) {
    AsCanvas(ccanvas)->drawRRect(*AsRRect(crect), *AsPaint(cpaint));
}

void sk_canvas_draw_circle(sk_canvas_t* ccanvas, float cx, float cy, float rad, const sk_paint_t* cpaint) {
    AsCanvas(ccanvas)->drawCircle(cx, cy, rad, *AsPaint(cpaint));
}

void sk_canvas_draw_oval(sk_canvas_t* ccanvas, const sk_rect_t* crect, const sk_paint_t* cpaint) {
    AsCanvas(ccanvas)->drawOval(*AsRect(crect), *AsPaint(cpaint));
}

void sk_canvas_draw_path(sk_canvas_t* ccanvas, const sk_path_t* cpath, const sk_paint_t* cpaint) {
    AsCanvas(ccanvas)->drawPath(*AsPath(cpath), *AsPaint(cpaint));
}

void sk_canvas_flush(sk_canvas_t* ccanvas) {
    AsCanvas(ccanvas)->flush();
}

void sk_canvas_draw_arc(sk_canvas_t* ccanvas, const sk_rect_t* oval, float startAngle, float sweepAngle, bool useCenter, const sk_paint_t* paint) {
    AsCanvas(ccanvas)->drawArc(*AsRect(oval), startAngle, sweepAngle, useCenter, *AsPaint(paint));
}

void sk_canvas_draw_text_blob (sk_canvas_t* ccanvas, sk_textblob_t* text, float x, float y, const sk_paint_t* cpaint) {
    AsCanvas(ccanvas)->drawTextBlob(AsTextBlob(text), x, y, *AsPaint(cpaint));
}
