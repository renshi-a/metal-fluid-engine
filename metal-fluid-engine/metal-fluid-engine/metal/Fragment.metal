//
//  Fragment.metal
//  metal-fluid-engine
//
//  Created by Renshi Asada on 2024/10/28.
//

#include "ShaderTypes.h"

#include <metal_stdlib>
using namespace metal;

struct FragmentIn {
    float4 position [[position]];
};

float plot(float2 v) {
    return smoothstep(0.02, 0.0, abs(v.x - v.y));
}

[[fragment]]
float4 gl_fragcoord_fragment_main(FragmentIn in [[stage_in]],
                                 constant GLFragCoordFragmentUniforms& uniforms [[buffer(0)]] ) {
    float2 v = in.position.xy / uniforms.resolution;
    
    float y = v.x;
    float3 col = float3(y);
    
    
    float pct = plot(v);
    col = (1.0 - pct) * col + pct * float3(1.0, 0.0, 0.0);
    
    return float4(col, 1.0);
}
