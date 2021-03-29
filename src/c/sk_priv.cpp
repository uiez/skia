#include "src/c/sk_types_priv.h"

void SkTraceMemoryDumpWrapper::dumpNumericValue(const char* dumpName,
                                                const char* valueName,
                                                const char* units,
                                                uint64_t value) {
    dump->dumpNumericValue(dump->context, dumpName, valueName, units, value);
}

void SkTraceMemoryDumpWrapper::dumpStringValue(const char* dumpName,
                                               const char* valueName,
                                               const char* value) {
    dump->dumpStringValue(dump->context, dumpName, valueName, value);
}

void SkTraceMemoryDumpWrapper::setMemoryBacking(const char* dumpName,
                                                const char* backingType,
                                                const char* backingObjectId) {}

void SkTraceMemoryDumpWrapper::setDiscardableMemoryBacking(
        const char* dumpName, const SkDiscardableMemory& discardableMemoryObject) {}

SkTraceMemoryDump::LevelOfDetail SkTraceMemoryDumpWrapper::getRequestedDetails() const {
    return SkTraceMemoryDump::kObjectsBreakdowns_LevelOfDetail;
}

bool SkTraceMemoryDumpWrapper::shouldDumpWrappedObjects() const { return true; }
