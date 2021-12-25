//
//  rose.cpp
//
//  Created by Kirby on 11/12/16
//  ampA + ampB * cos(petalM/petalN * theta)
//

#include <iostream>
#include "rose.h"

void Rose::setup(ofPoint _origin, ofPoint _petal, ofColor _color, float _pct){
    // center of rose
    origin.set(_origin);
    petal.set(_petal);
    
    angle = radian = x = y = 0.0f;
    angleadder = .1;
    
    // colors
    color.set(_color);
    pink.set(255,0,255);
    blue.set(0,255,255);
    pct = _pct;
    pct = pct / 255;
    increment = .01f;
    
    // size of the rose : ampA and ampB
    // if a<b => 2 sets of petals, petals meet at origin, smaller set of length b-a, larger set of length b+a
    // if a>b => 2 sets of petals, petals do not meet origin, smaller set of length a-b, larger set of length a+b
    // if a=b length of petals is 2a
    ampA = 15;
    ampB = 15;
    
    // Max theta to view whole graph
    if (petal.x/petal.y != 1) {
        theta = 2 * petal.y * 180;
    } else{
        theta = 360;
    }
}

//--------------------------------------------------------------
void Rose::update(){
    if (angle<=360) {
        angle += angleadder;
    } else {
        angle = 0;
    }
    
    pct += increment;
    if (pct > 1) {
        pct = 1;
        increment *= -1;
    }
    if (pct < 0) {
        pct = 0;
        increment *= -1;
    }
    interpolateByPct();
}

//--------------------------------------------------------------
void Rose::draw(){
    
    ofSetColor(color);

    for (int i=0; i<theta; i+=10) {
        radian = PI/180 * ((angle + i)); // convert degrees to radians
        p = ampA + ampB * cos(petal.x / petal.y * radian); // calculate polar coordinates
        x = origin.x + p * cos(radian); // convert to Cartesian 'x'
        y = origin.y + p * sin(radian); // convert to Cartesian 'y'
        ofDrawCircle(x, y, .8); // draw
    }
    
    ofDrawBitmapString( ofToString(petal.x) + ", " + ofToString(petal.y), origin.x, origin.y);
}

//--------------------------------------------------------------
void Rose::interpolateByPct(){
    color.r = (1-pct) * pink.r + pct * blue.r;
    color.g = (1-pct) * pink.g + pct * blue.g;
}
