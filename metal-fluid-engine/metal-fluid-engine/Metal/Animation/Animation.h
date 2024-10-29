//
//  Animation.h
//  metal-fluid-engine
//
//  Created by Renshi Asada on 2024/10/29.
//

#ifndef Animation_h
#define Animation_h

#include "Frame.h"

class Animation {
protected:
    // 更新したとき
    virtual void onUpdate(const Frame& frame) = 0;
    
public:
    // コンストラクタ
    Animation();
    // デストラクタ
    virtual ~Animation();
    // 更新する
    void update(const Frame& frame);
};

#endif /* Animation_h */
