#include <metal_stdlib>
#include <simd/simd.h>
using namespace metal;
struct Inputs {
    int a;
    uint b;
};
struct Outputs {
    float4 sk_FragColor [[color(0)]];
};


fragment Outputs fragmentMain(Inputs _in [[stage_in]], bool _frontFacing [[front_facing]], float4 _fragCoord [[position]]) {
    Outputs _out;
    int _skTemp0;
    int _skTemp1;
    uint _skTemp2;
    _out.sk_FragColor.x = float((_skTemp0 = (_in.a), _skTemp1 = (select(_skTemp0, ~_skTemp0, _skTemp0 < 0)), select(int(clz(_skTemp1)), int(-1), _skTemp1 == int(0))));
    _out.sk_FragColor.y = float((_skTemp2 = (_in.b), select(int(clz(_skTemp2)), int(-1), _skTemp2 == uint(0))));
    return _out;
}
