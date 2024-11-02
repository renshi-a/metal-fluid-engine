//
//  Animation.cpp
//  metal-fluid-engine
//
//  Created by Renshi Asada on 2024/10/29.
//

#include "Animation.h"

Animation::Animation() {
}

Animation::~Animation() {
    
}

void Animation::update(const Frame& frame) {
    onUpdate(frame);
}
