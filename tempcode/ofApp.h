#pragma once
#include "ofMain.h"
#include "ofxGui.h"
class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void playPressed();
	void stopPressed();
	void pausePressed();

	ofxPanel controller;
	ofxIntSlider rValue, gValue, bValue, radius;
	ofxFloatSlider xPos, yPos, vol;
	ofxButton play, stop;

	ofSoundPlayer mySnd;
};