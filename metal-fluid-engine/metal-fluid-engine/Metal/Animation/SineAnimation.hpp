//
//  SineAnimation.hpp
//  metal-fluid-engine
//
//  Created by Renshi Asada on 2024/10/29.
//

#ifndef SineAnimation_hpp
#define SineAnimation_hpp

#include "Animation.h"
#include <cmath>

class SineAnimation: public Animation {
    
protected:
    void onUpdate(const Frame &frame) override {
        auto exp = std::exp(-frame.timeInSeconds());
        value = exp * std::sin(10 * frame.timeInSeconds());
    }
    
public:
    // sin値
    double value = 0.0;
};

#endif /* SineAnimation_hpp */
