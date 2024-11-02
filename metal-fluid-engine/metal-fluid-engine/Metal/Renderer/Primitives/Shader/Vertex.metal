//
//  Vertex.metal
//  metal-fluid-engine
//
//  Created by Renshi Asada on 2024/10/28.
//

#include "ShaderTypes.h"

#include <metal_stdlib>

using namespace metal;

struct VertexOut {
    float4 position [[position]];
    float2 normalizedCoodinate;
};

vertex VertexOut vertex_main(uint vertexID [[vertex_id]],
                             constant Vertex* normalizedCoodinates [[buffer(0)]],
                             constant VertexUniforms& uniforms [[buffer(1)]]) {
    // input
    float2 resolution = uniforms.resolution;
    
    // output
    VertexOut out;
    float2 position = uniforms.center + uniforms.radius * normalizedCoodinates[vertexID].position;
    float2 zeroToOne = position / resolution;
    float2 zeroToTwo = zeroToOne * 2.0;
    float2 clipSpace = zeroToTwo - 1.0;
    float2 yFlip = { 1.0, -1.0 };
    out.position = float4(clipSpace * yFlip, 0.0, 1.0);
    out.normalizedCoodinate = normalizedCoodinates[vertexID].position;
    
    return out;
}
