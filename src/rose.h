//
//  rose.h
//
//  Created by Kirby on 11/12/16
//
//

#include "ofMain.h"

#ifndef rose_h
#define rose_h

class Rose{
public:
    
    void setup( ofPoint _origin, ofPoint _petal, ofColor _color, float _pct);
    void update();
    void draw();
    void interpolateByPct();
    
    ofPoint origin;
    ofPoint petal;
    
    float angle, angleadder;
    float ampA, ampB;
    float radian, x, p, y, theta;
    
    ofColor pink, blue, color;
    
    float pct, increment;
    
};




#endif /* rose.h */
