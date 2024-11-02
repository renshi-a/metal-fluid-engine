//
//  SineAnimationRenderer.cpp
//  metal-fluid-engine
//
//  Created by Renshi Asada on 2024/10/30.
//

#include "SineAnimationRenderer.hpp"

// 円のサイズ
constexpr float circleSize = 18.0;

// コンストラクタ
SineAnimationRenderer::SineAnimationRenderer(id<MTLDevice> mtlDevice) {
    renderer = std::make_unique<CircleRenderer>(mtlDevice);
}

// デストラクタ
SineAnimationRenderer::~SineAnimationRenderer() {
    
}

// 描画する
void SineAnimationRenderer::render(Frame frame, const SineAnimation& animation, MTKView* view) {
    auto x = frame.index;
    auto b = view.drawableSize.height / 2.0;
    auto y = b + animation.value * b;
    auto p = Vector(x, y);
    drawCircle(p, circleSize, view);
}

void SineAnimationRenderer::drawCircle(Vector center, float radius, MTKView* view) {
    renderer->draw(center, radius, view);
}
