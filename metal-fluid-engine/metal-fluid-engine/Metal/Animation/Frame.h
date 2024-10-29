//
//  Frame.h
//  metal-fluid-engine
//
//  Created by Renshi Asada on 2024/10/29.
//

#ifndef Frame_h
#define Frame_h

struct Frame {
    unsigned int index = 0;
    double timeIntervalInSecounds = 1.0 / 60.0;
    
    // コンストラクタ
    Frame();
    
    double timeInSeconds() const { return index * timeIntervalInSecounds; }
    
    void advance() { ++index; }
    
    void advance(int delta) { index += delta;}
    
    Frame& operator++();
    
    Frame operator++(int);
};

#endif /* Frame_h */
