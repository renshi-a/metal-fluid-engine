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
    float2 normalizedCoodinate;
};

float sdf_circle(float2 p, float r) {
    return length(p) - r;
}

fragment float4 fragment_main(FragmentIn in [[stage_in]],
                              constant FragmentUniforms& uniforms [[buffer(0)]] ) {
    float distance = sdf_circle(in.normalizedCoodinate, 1.0);
    if (distance > 0) {
        discard_fragment();
    } else {
        float alpha = 1.0;
        if (uniforms.antialiasingType == 0) { // アンチエイリアシングなし
            alpha = 1.0;
        } else if (uniforms.antialiasingType == 1) {
            alpha = smoothstep(0.0, 0.05, -distance);
        } else if (uniforms.antialiasingType == 2) {
            alpha = clamp(-distance / 0.01, 0.0, 1.0);
        } else if (uniforms.antialiasingType == 3) {
            float v = -distance / fwidth(-distance);
            alpha = clamp(v - 0.5, 0.0, 1.0);
        }
        return float4(1.f, 0.0f, 0.0f, 1.0 * alpha);
    }
}
