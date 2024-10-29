//
//  Scene.m
//  metal-fluid-engine
//
//  Created by Renshi Asada on 2024/10/29.
//

#include "Scene.h"

@interface Scene()

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

}

/// 更新する
- (void)update {
    
}

- (void)draw:(nonnull MTKView *)view {

}

@end
