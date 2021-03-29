#ifndef sk_graphics_DEFINED
#define sk_graphics_DEFINED

#include "include/c/sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API void sk_graphics_init();
SK_C_API void sk_graphics_terminate();
SK_C_API size_t sk_graphics_get_font_cache_limit();
SK_C_API void sk_graphics_set_font_cache_limit(size_t bytes);
SK_C_API size_t sk_graphics_get_resource_cache_limit();
SK_C_API void sk_graphics_set_resource_cache_limit(size_t bytes);
SK_C_API void sk_graphics_dump_memory_statistics(sk_trace_memory_dump_t *dump);

SK_C_PLUS_PLUS_END_GUARD

#endif
