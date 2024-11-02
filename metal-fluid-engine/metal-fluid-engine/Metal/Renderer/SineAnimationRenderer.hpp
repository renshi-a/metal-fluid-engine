//
//  SineAnimationRenderer.hpp
//  metal-fluid-engine
//
//  Created by Renshi Asada on 2024/10/30.
//

#ifndef SineAnimationRenderer_hpp
#define SineAnimationRenderer_hpp

#include "Primitives/CircleRenderer.hpp"
#include "../Math/Vector.hpp"
#include "../Animation/SineAnimation.hpp"
#include <memory>

class SineAnimationRenderer {
private:
    // レンダラー
    std::unique_ptr<CircleRenderer> renderer;
    // 円を描画する
    void drawCircle(Vector center, float radius, MTKView* view);
    
public:
    // コンストラクタ
    SineAnimationRenderer(id<MTLDevice> mtlDevice);
    // デストラクタ
    ~SineAnimationRenderer();
    // 描画する
    void render(Frame frame, const SineAnimation& animation, MTKView* view);
};

#endif /* SineAnimationRenderer_hpp */
