//
//  Scene.m
//  metal-fluid-engine
//
//  Created by Renshi Asada on 2024/10/29.
//

#include "Frame.h"
#include "../Renderer/SineAnimationRenderer.hpp"
#include "SineAnimation.hpp"
#include "Scene.h"

@interface Scene()

@property (nonatomic) Frame* frame;
@property (nonatomic) SineAnimation* animation;
@property (nonatomic) SineAnimationRenderer* renderer;

@end

@implementation Scene

static Scene* sharedInstance = nil;

+ (instancetype)shared {
    if (sharedInstance == nil) {
        sharedInstance = [[self alloc] init];
    }
    return sharedInstance;
}

/// 設定する
- (void)setup:(nonnull MTKView *)view {
    self.frame = new Frame();
    self.animation = new SineAnimation();
    self.renderer = new SineAnimationRenderer(view.device);
}

/// 更新する
- (void)update {
    if (self.animation == nullptr) {
        return;
    }
    self.animation->update(*self.frame);
}

- (void)draw:(nonnull MTKView *)view {
    if (self.renderer == nullptr) {
        return;
    }
    self.renderer->render(*self.frame, *self.animation, view);
    self.frame->advance();
}

- (void)clear {
    delete self.animation;
    delete self.renderer;
}

@end
