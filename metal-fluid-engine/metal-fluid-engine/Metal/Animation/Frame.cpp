//
//  Frame.cpp
//  metal-fluid-engine
//
//  Created by Renshi Asada on 2024/10/29.
//

#include "Frame.h"

Frame& Frame::operator++() {
    advance();
    return *this;
}

Frame Frame::operator++(int i) {
    Frame res = *this;
    advance();
    return res;
}
