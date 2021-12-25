#pragma once

#include "ofMain.h"
#include "rose.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        vector <Rose> _roses;
        
        vector <ofPoint> _centers;
        ofPoint _center;

        vector <ofPoint> _petals;
        ofPoint _petal;
        
        vector <ofColor> _colors;
        ofColor _color;
        vector <float> _pcts;
        float _pct;
};
