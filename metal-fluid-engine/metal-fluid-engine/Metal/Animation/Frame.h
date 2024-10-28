//
//  Frame.h
//  metal-fluid-engine
//
//  Created by Renshi Asada on 2024/10/29.
//

#ifndef Frame_h
#define Frame_h

final struct Frame {
    unsigned int index = 0;
    double timeIntervalInSecounds = 1.0 / 60.0;
    
    double timeInSeconds() const {
        return index * timeIntervalInSecounds;
    }
    
    void advance() {
        ++index;
    }
    
    void advance(unsigned int delta) {
        index += delta;
    }
};

#endif /* Frame_h */
