//
//  Scene.h
//  metal-fluid-engine
//
//  Created by Renshi Asada on 2024/10/29.
//

#ifndef Scene_h
#define Scene_h

#import <Foundation/Foundation.h>

#include "Metal/Metal.h"
#include "MetalKit/MetalKit.h"

@interface Scene : NSObject

/// シングルトン
+ (instancetype _Nonnull )shared;
/// 設定する
- (void)setup:(nonnull MTKView *)view;
/// 更新する
- (void)update;
/// 描画する
- (void)draw:(nonnull MTKView *)view;
/// クリア
- (void)clear;

@end


#endif /* Scene_h */
