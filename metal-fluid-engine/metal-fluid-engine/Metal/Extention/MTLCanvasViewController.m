//
//  MTLCanvasViewController.m
//  metal-fluid-engine
//
//  Created by Renshi Asada on 2024/10/29.
//

#include "MTLCanvasViewController.h"

#import <Foundation/Foundation.h>
#import <Metal/Metal.h>

@implementation MTLCanvasViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    id<MTLDevice> device = MTLCreateSystemDefaultDevice();
    if (!device) {
        return;
    }
    
    MTKView *mtkView = [[MTKView alloc] initWithFrame:CGRectZero device:device];
    mtkView.translatesAutoresizingMaskIntoConstraints = NO;
    [self.view addSubview:mtkView];
    
    [NSLayoutConstraint activateConstraints:@[
        [mtkView.leadingAnchor constraintEqualToAnchor:self.view.leadingAnchor],
        [mtkView.trailingAnchor constraintEqualToAnchor:self.view.trailingAnchor],
        [mtkView.topAnchor constraintEqualToAnchor:self.view.topAnchor],
        [mtkView.bottomAnchor constraintEqualToAnchor:self.view.bottomAnchor]
    ]];
    
    mtkView.delegate = self;
    
    /// キャンバス初期化
}

- (void)drawInMTKView:(nonnull MTKView *)view {
    
    
}

- (void)mtkView:(nonnull MTKView *)view drawableSizeWillChange:(CGSize)size {
    NSLog(@"MTLCanvasViewController::drawableSizeWillChange()");
    NSLog(@"drawableSize.width = %f, drawableSize.height = %f", size.width, size.height);
    NSLog(@"view.width = %f, view.height = %f", view.frame.size.width, view.frame.size.height);
}

@end
