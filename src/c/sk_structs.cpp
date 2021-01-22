/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "src/c/sk_types_priv.h"

#include "include/core/SkCanvas.h"
#include "include/core/SkDocument.h"
#include "include/core/SkImageInfo.h"
#include "include/core/SkPaint.h"
#include "include/core/SkPoint.h"
#include "include/core/SkPoint3.h"
#include "include/core/SkRect.h"
#include "include/core/SkRSXform.h"
#include "include/core/SkSize.h"
#include "include/core/SkSurfaceProps.h"
#include "include/core/SkTextBlob.h"
#include "include/core/SkTime.h"
#include "include/effects/SkHighContrastFilter.h"
#include "src/core/SkMask.h"

#if SK_SUPPORT_GPU
#include "include/gpu/GrTypes.h"
#include "include/gpu/GrContextOptions.h"
#include "include/gpu/gl/GrGLTypes.h"

#endif

#if __cplusplus >= 199711L

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define ASSERT_MSG(SK, C) "ABI changed, you must update the C structure for " TOSTRING(#SK) " to " TOSTRING(#C) "."

// custom mappings:
//  - sk_matrix_t

static_assert (sizeof (sk_point_t) == sizeof (SkPoint), ASSERT_MSG(SkPoint, sk_point_t));
static_assert (sizeof (sk_rect_t) == sizeof (SkRect), ASSERT_MSG(SkRect, sk_rect_t));
static_assert (sizeof (sk_imageinfo_t) == sizeof (SkImageInfo), ASSERT_MSG(SkImageInfo, sk_imageinfo_t));
static_assert (sizeof (sk_fontmetrics_t) == sizeof (SkFontMetrics), ASSERT_MSG(SkFontMetrics, sk_fontmetrics_t));
static_assert (sizeof (sk_highcontrastconfig_t) == sizeof (SkHighContrastConfig), ASSERT_MSG(SkHighContrastConfig, sk_highcontrastconfig_t));
static_assert (sizeof (sk_textblob_builder_runbuffer_t) == sizeof (SkTextBlobBuilder::RunBuffer), ASSERT_MSG(SkTextBlobBuilder::RunBuffer, sk_textblob_builder_runbuffer_t));
static_assert (sizeof (sk_color4f_t) == sizeof (SkColor4f), ASSERT_MSG(SkColor4f, sk_color4f_t));

#if SK_SUPPORT_GPU
static_assert (sizeof (gr_gl_framebufferinfo_t) == sizeof (GrGLFramebufferInfo), ASSERT_MSG(GrGLFramebufferInfo, gr_gl_framebufferinfo_t));
#endif

#endif
