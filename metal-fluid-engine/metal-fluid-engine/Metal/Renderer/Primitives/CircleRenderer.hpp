//
//  CircleRenderer.hpp
//  metal-fluid-engine
//
//  Created by Renshi Asada on 2024/10/31.
//

#ifndef CircleRenderer_hpp
#define CircleRenderer_hpp

#include "../../Math/Vector.hpp"

#include "Metal/Metal.h"
#include "MetalKit/MetalKit.h"

class CircleRenderer {
private:
    /// コマンドキュー
    id<MTLDevice> device;
    /// コマンドキュー
    id<MTLCommandQueue> commandQueue;
    /// 一つのドローコールの間保持しているコマンドバッファー
    id<MTLCommandBuffer> commandBuffer;
    /// レンダーパイプラインステート
    id<MTLRenderPipelineState> renderPipelineState;
    /// インデックスバッファ
    id<MTLBuffer> indexBuffer;
    /// エンコーダー
    id<MTLRenderCommandEncoder> encorder;
    /// 初回のレンダリングが完了している
    bool isRenderedFirstFrame;
    /// RenderPipelineStateを作成する
    void createRenderPipelineState();
    /// バッファを作成する
    void createBuffer();
    
public:
    /// コンストラクタ
    CircleRenderer(id<MTLDevice> mtlDevice);
    /// 描画する
    void draw(Vector center, float radius, MTKView* view);
};

#endif /* CircleRenderer_hpp */
