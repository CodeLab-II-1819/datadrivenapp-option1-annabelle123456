#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofTrueTypeFont myFont1;
		ofTrueTypeFont myFont2;
		ofImage woodenFrame;
		ofImage searchbar;
		ofImage logo;
};
