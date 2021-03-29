#include "include/core/SkGraphics.h"

#include "include/c/sk_graphics.h"
#include "src/c/sk_types_priv.h"

void sk_graphics_init() {
    SkGraphics::Init();
}
void sk_graphics_terminate() {
    SkGraphics::Term();
}
size_t sk_graphics_get_font_cache_limit() {
    return SkGraphics::GetFontCacheLimit();
}
void sk_graphics_set_font_cache_limit(size_t bytes) {
    SkGraphics::SetFontCacheLimit(bytes);
}
size_t sk_graphics_get_resource_cache_limit() {
    return SkGraphics::GetResourceCacheTotalByteLimit();
}
void sk_graphics_set_resource_cache_limit(size_t bytes) {
    SkGraphics::SetResourceCacheTotalByteLimit(bytes);
}

void sk_graphics_dump_memory_statistics(sk_trace_memory_dump_t *dump) {
    SkTraceMemoryDumpWrapper dumper(dump);
    SkGraphics::DumpMemoryStatistics(&dumper);
}