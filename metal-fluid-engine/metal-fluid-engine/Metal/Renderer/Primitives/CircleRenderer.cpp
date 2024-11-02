//
//  CircleRenderer.cpp
//  metal-fluid-engine
//
//  Created by Renshi Asada on 2024/10/31.
//

#include "Shader/ShaderTypes.h"
#include "CircleRenderer.hpp"

CircleRenderer::CircleRenderer(id<MTLDevice> mtlDevice) {
    device = mtlDevice;
    commandQueue = [device newCommandQueue];
    isRenderedFirstFrame = false;
    createBuffer();
    createRenderPipelineState();
}

void CircleRenderer::draw(Vector center, float radius, MTKView* view) {
    if (!isRenderedFirstFrame) {
        auto pixelFormat = MTLPixelFormat::MTLPixelFormatRGBA8Unorm_sRGB;
        [view setColorPixelFormat:pixelFormat];
        auto clearColor = MTLClearColorMake(0.8, 0.8, 0.8, 1.0);
        [view setClearColor: clearColor];
    }
    commandBuffer = [commandQueue commandBuffer];
    
    auto descriptor = [view currentRenderPassDescriptor];
    descriptor.colorAttachments[0].loadAction = MTLLoadActionClear;
    encorder = [commandBuffer renderCommandEncoderWithDescriptor: descriptor];
    
    Vertex normalizedCoordinates[] = {
        { { -1.0, 1.0} },
        { { 1.0, 1.0 } },
        { { 1.0, -1.0 } },
        { { -1.0, -1.0 } },
    };
  
    auto resolusion = simd_make_float2(float(view.drawableSize.width),
                                       float(view.drawableSize.height));
    auto c = simd_make_float2(center.x, center.y);
    auto vertexUniforms = VertexUniforms(resolusion, c, radius);
    
    /// fragments
    int8_t type = 3;
    auto fragmentUniforms = FragmentUniforms(type);
    
    [encorder setRenderPipelineState: renderPipelineState];
    [encorder setVertexBytes: &normalizedCoordinates length: sizeof(normalizedCoordinates) atIndex: 0];
    [encorder setVertexBytes: &vertexUniforms length: sizeof(vertexUniforms) atIndex: 1];
    [encorder setFragmentBytes: &fragmentUniforms length: sizeof(fragmentUniforms) atIndex: 0];
    [encorder drawIndexedPrimitives: MTLPrimitiveTypeTriangle
                              indexCount: 6
                               indexType: MTLIndexTypeUInt16
                             indexBuffer: indexBuffer
                       indexBufferOffset: 0
                        instanceCount: 2];
    
    [encorder endEncoding];
    [commandBuffer presentDrawable: [view currentDrawable]];
    [commandBuffer commit];
    
    if (!isRenderedFirstFrame) {
        isRenderedFirstFrame = true;
    }
}

void CircleRenderer::createRenderPipelineState() {
    auto shaderLibrary = [device newDefaultLibrary];
    auto vertexFunction = [shaderLibrary newFunctionWithName: @"vertex_main"];
    auto fragmentFuction = [shaderLibrary newFunctionWithName: @"fragment_main"];
    
    auto descriptor = [[MTLRenderPipelineDescriptor alloc] init];
    auto colorAttachment = [descriptor colorAttachments][0];
    
    [colorAttachment setPixelFormat: MTLPixelFormat::MTLPixelFormatRGBA8Unorm_sRGB];
    [colorAttachment setBlendingEnabled: true];
    [colorAttachment setRgbBlendOperation: MTLBlendOperationAdd];
    [colorAttachment setAlphaBlendOperation: MTLBlendOperationAdd];
    [colorAttachment setSourceRGBBlendFactor: MTLBlendFactorSourceAlpha];
    [colorAttachment setSourceAlphaBlendFactor: MTLBlendFactorSourceAlpha];
    [colorAttachment setDestinationRGBBlendFactor: MTLBlendFactorOneMinusSourceAlpha];
    [colorAttachment setDestinationAlphaBlendFactor: MTLBlendFactorOneMinusSourceAlpha];
    [descriptor setVertexFunction: vertexFunction];
    [descriptor setFragmentFunction: fragmentFuction];
    NSError* error;
    renderPipelineState = [device newRenderPipelineStateWithDescriptor: descriptor error: &error];
}

void CircleRenderer::createBuffer() {
    uint16_t indices[] = {
        0, 1, 3,
        1, 2, 3,
    };
    
    const size_t indexDataSize = sizeof( indices );
    indexBuffer = [device newBufferWithLength: indexDataSize options: MTLResourceCPUCacheModeShift ];
    memcpy([indexBuffer contents], indices, indexDataSize);
}
