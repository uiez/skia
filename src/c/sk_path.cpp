/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/core/SkPath.h"

#include "include/c/sk_path.h"

#include "src/c/sk_types_priv.h"

void sk_path_add_arc(sk_path_t* cpath, const sk_rect_t* crect, float startAngle, float sweepAngle) {
    AsPath(cpath)->addArc(*AsRect(crect), startAngle, sweepAngle);
}

void sk_path_set_filltype(sk_path_t* cpath, sk_path_filltype_t cfilltype) {
    AsPath(cpath)->setFillType((SkPathFillType)cfilltype);
}

void sk_path_reset (sk_path_t* cpath) {
    AsPath (cpath)->reset();
}

void sk_path_rewind (sk_path_t* cpath) {
    AsPath (cpath)->rewind();
}

void sk_path_add_path_offset (sk_path_t* cpath, sk_path_t* other, float dx, float dy, sk_path_add_mode_t add_mode) {
    AsPath (cpath)->addPath (AsPath (*other), dx, dy, (SkPath::AddPathMode) add_mode);
}

sk_path_t* sk_path_new(void) {
    return ToPath(new SkPath());
}

void sk_path_delete(sk_path_t* cpath) {
    delete AsPath(cpath);
}

void sk_path_move_to(sk_path_t* cpath, float x, float y) {
    AsPath(cpath)->moveTo(x, y);
}

void sk_path_line_to(sk_path_t* cpath, float x, float y) {
    AsPath(cpath)->lineTo(x, y);
}

void sk_path_quad_to(sk_path_t* cpath, float x0, float y0, float x1, float y1) {
    AsPath(cpath)->quadTo(x0, y0, x1, y1);
}

void sk_path_conic_to(sk_path_t* cpath, float x0, float y0, float x1, float y1, float w) {
    AsPath(cpath)->conicTo(x0, y0, x1, y1, w);
}

void sk_path_cubic_to(sk_path_t* cpath, float x0, float y0, float x1, float y1, float x2, float y2) {
    AsPath(cpath)->cubicTo(x0, y0, x1, y1, x2, y2);
}

void sk_path_arc_to(sk_path_t* cpath, float rx, float ry, float xAxisRotate, sk_path_arc_size_t largeArc, sk_path_direction_t sweep, float x, float y) {
    AsPath(cpath)->arcTo(rx, ry, xAxisRotate, (SkPath::ArcSize)largeArc, (SkPathDirection)sweep, x, y);
}

void sk_path_arc_to_with_oval(sk_path_t* cpath, const sk_rect_t* oval, float startAngle, float sweepAngle, bool forceMoveTo) {
    AsPath(cpath)->arcTo(*AsRect(oval), startAngle, sweepAngle, forceMoveTo);
}

void sk_path_arc_to_with_points(sk_path_t* cpath, float x1, float y1, float x2, float y2, float radius) {
    AsPath(cpath)->arcTo(x1, y1, x2, y2, radius);
}

void sk_path_close(sk_path_t* cpath) {
    AsPath(cpath)->close();
}

void sk_path_add_rect(sk_path_t* cpath, const sk_rect_t* crect, sk_path_direction_t cdir) {
    AsPath(cpath)->addRect(*AsRect(crect), (SkPathDirection)cdir);
}

void sk_path_add_rrect(sk_path_t* cpath, const sk_rrect_t* crect, sk_path_direction_t cdir) {
    AsPath(cpath)->addRRect(*AsRRect(crect), (SkPathDirection)cdir);
}

void sk_path_add_oval(sk_path_t* cpath, const sk_rect_t* crect, sk_path_direction_t cdir) {
    AsPath(cpath)->addOval(*AsRect(crect), (SkPathDirection)cdir);
}

void sk_path_add_circle(sk_path_t* cpath, float x, float y, float radius, sk_path_direction_t dir) {
    AsPath(cpath)->addCircle(x, y, radius, (SkPathDirection)dir);
}

void sk_path_get_bounds(const sk_path_t* cpath, sk_rect_t* crect) {
    *crect = ToRect(AsPath(cpath)->getBounds());
}

void sk_path_compute_tight_bounds(const sk_path_t* cpath, sk_rect_t* crect) {
    *crect = ToRect(AsPath(cpath)->computeTightBounds());
}

bool sk_path_contains (const sk_path_t* cpath, float x, float y) {
    return AsPath(cpath)->contains(x, y);
}
