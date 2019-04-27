#include "ofApp.h"

void ofApp::setup() {
	controller.setup();
	controller.add(rValue.setup("R Value, 0, 0, 255"));
	controller.add(gValue.setup("G Value, 0, 0, 255"));
	controller.add(bValue.setup("B Value", 0, 0, 255));
	controller.add(radius.setup("Radius", 30, 10, 300));
	controller.add(xPos.setup("x Position", 800, 0, 600));
	controller.add(yPos.setup("y Position", 10, 0, 600));
	controller.add(vol.setup("Volume", 1.0, 0.0, 1.0));
	controller.add(play.setup("Play"));
	controller.add(stop.setup("Stop"));

	play.addListener(this, &ofApp::playPressed);
	stop.addListener(this, &ofApp::stopPressed);

	mySnd.load("sound.mp3");
	mySnd.setLoop(true);

}

void ofApp::update() {
	mySnd.setVolume(vol);
}

void ofApp::draw() {
	ofSetColor(rValue, gValue, bValue);
	ofDrawCircle(xPos, yPos, radius);
	controller.draw();
}

void ofApp::playPressed() {
	mySnd.play();
	cout << "hi" << endl;
}

void ofApp::stopPressed() {
	mySnd.stop();
}
void ofApp::pausePressed() {
	if (mySnd.isPlaying()) {
		mySnd.setPaused(true);
	}
	else {
		mySnd.setPaused(false);
	}