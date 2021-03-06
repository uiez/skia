

/**************************************************************************************************
 *** This file was autogenerated from GrTrackedInUniform.fp; do not modify.
 **************************************************************************************************/
#ifndef GrTrackedInUniform_DEFINED
#define GrTrackedInUniform_DEFINED

#include "include/core/SkM44.h"
#include "include/core/SkTypes.h"


#include "src/gpu/GrFragmentProcessor.h"

class GrTrackedInUniform : public GrFragmentProcessor {
public:
    static std::unique_ptr<GrFragmentProcessor> Make(SkRect color) {
        return std::unique_ptr<GrFragmentProcessor>(new GrTrackedInUniform(color));
    }
    GrTrackedInUniform(const GrTrackedInUniform& src);
    std::unique_ptr<GrFragmentProcessor> clone() const override;
    const char* name() const override { return "TrackedInUniform"; }
    SkRect color;
private:
    GrTrackedInUniform(SkRect color)
    : INHERITED(kGrTrackedInUniform_ClassID, kNone_OptimizationFlags)
    , color(color) {
    }
    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;
    void onGetGLSLProcessorKey(const GrShaderCaps&, GrProcessorKeyBuilder*) const override;
    bool onIsEqual(const GrFragmentProcessor&) const override;
#if GR_TEST_UTILS
    SkString onDumpInfo() const override;
#endif
    GR_DECLARE_FRAGMENT_PROCESSOR_TEST
    using INHERITED = GrFragmentProcessor;
};
#endif
