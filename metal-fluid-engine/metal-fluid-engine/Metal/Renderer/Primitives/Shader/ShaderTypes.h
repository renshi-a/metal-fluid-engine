//
//  ShaderTypes.h
//  metal-fluid-engine
//
//  Created by Renshi Asada on 2024/10/28.
//

#ifndef ShaderTypes_h
#define ShaderTypes_h

#include <simd/simd.h>

/// 頂点情報
typedef struct Vertex {
    vector_float2 position;
} Vertex;

/// 頂点のためのユニフォーム変数
typedef struct VertexUniforms {
public:
    /// 画面サイズ
    simd_float2 resolution;
    /// 中心
    simd_float2 center;
    /// 半径
    float radius;
    
    /// コンストラクタ
    VertexUniforms(simd_float2 res, simd_float2 c, float rad) {
        resolution = res;
        center = c;
        radius = rad;
    }
} VertexUniforms;

/// フラグメントのためのユニフォーム変数
typedef struct FragmentUniforms {
public:
    /// アンチエイリアシングのタイプ
    /// 0: なし
    /// 1: smoothStep
    /// 2: devide fixed
    /// 3: fwidth
    uint8_t antialiasingType;
    /// コンストラクタ
    FragmentUniforms(uint8_t v) {
        antialiasingType = v;
    }
} FragmentUniforms;

#endif /* ShaderTypes_h */
