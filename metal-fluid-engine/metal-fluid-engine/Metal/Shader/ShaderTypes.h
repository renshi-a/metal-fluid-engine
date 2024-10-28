//
//  ShaderTypes.h
//  metal-fluid-engine
//
//  Created by Renshi Asada on 2024/10/28.
//

#ifndef ShaderTypes_h
#define ShaderTypes_h

#include <simd/simd.h>

typedef struct GLFragCoordVertex {
    vector_float2 position;
} GLFragCoordVertex;

typedef struct GLFragCoordVertexUniforms {
    simd_float2 resolution;
} GLFragCoordVertexUniforms;

typedef struct GLFragCoordFragmentUniforms {
    simd_float2 resolution;
} GLFragCoordFragmentUniforms;


#endif /* ShaderTypes_h */
