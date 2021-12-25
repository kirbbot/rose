#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofSetCircleResolution(100);
    ofSetWindowShape(810, 810);
    ofBackground(0,13,25);
    ofSetFrameRate(29);
    
    // grid / petals
    for (int x=0; x<9; x++) {
        for (int y=0; y<9; y++) {
            _center.set(45 + 90 * x, 45 + 90 * y);
            _centers.push_back(_center);
            
            _petal.set(x + 1,y + 1);
            _petals.push_back(_petal);
            
            _color.r = 255 - 15 * (x + y);
            _color.g = 0 + 15 * (x + y);
            _color.b = 255;
            _colors.push_back(_color);

            _pct = _color.g;
            _pcts.push_back(_pct);
        }
    }
    
    // roses
    for (int i=0; i<_centers.size(); i++){
        Rose _rose;
        _rose.setup(_centers[i], _petals[i], _colors[i], _pcts[i]);
        _roses.push_back(_rose);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i=0; i<_roses.size(); i++) {
        _roses[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i<_roses.size(); i++) {
        _roses[i].draw();
    }
//    
//    ofSaveFrame();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}