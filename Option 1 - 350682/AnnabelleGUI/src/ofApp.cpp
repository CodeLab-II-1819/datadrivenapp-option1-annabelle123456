#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	myFont1.load("Lobster-Regular.ttf", 30);
	myFont2.load("IndieFlower.ttf", 18);

	woodenFrame.loadImage("WoodenFrame.png");
	searchbar.loadImage("searchbar.png");
	logo.loadImage("twitter.png");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(247, 168, 203);

	logo.draw(ofGetWidth() / 2 - 140, ofGetHeight() / 2 - 380, 60, 60);

	// Search Box
	ofSetColor(255);
	ofDrawRectangle(260, 60, 520, 110);
	// Search Frame
	searchbar.draw(260, 60);
	searchbar.resize(520, 110);




	// Top Box
	ofSetColor(255);
	ofDrawRectangle(260, 180, 520, 180);
	// Top Frame
	woodenFrame.draw(260, 180);
	woodenFrame.resize(520, 180);
	// Middle Box
	ofSetColor(255);
	ofDrawRectangle(260, 370, 520, 180);
	// Middle Frame
	woodenFrame.draw(260, 370);
	woodenFrame.resize(520, 180);

	// Bottom Box
	ofSetColor(255);
	ofDrawRectangle(260, 560, 520, 180);
	// Bottom Frame
	woodenFrame.draw(260, 560);
	woodenFrame.resize(520, 180);



	//Title
	myFont1.drawString("Tweet Tweet", 440, 40);

	//Search Bar 
	ofSetColor(0);
	myFont2.drawString("Search", 485, 125);

	//Tweets Text 
	myFont2.drawString("Tweets with Uber", 430, 230);
	myFont2.drawString("Tweets with Dreamworks", 390, 280);
	myFont2.drawString("Tweets with Paris", 430, 320);

	//Count Text 
	myFont2.drawString("Count tweets with LGBT", 400, 420);
	myFont2.drawString("Count tweets with Politics", 390, 450);
	myFont2.drawString("Count tweets with Technology", 370, 480);
	myFont2.drawString("Count tweets with Money", 390, 513);

	//Tweets from Twitter Users 
	myFont2.drawString("Donald Trump", 440, 630);
	myFont2.drawString("JLo", 500, 690);



	// Top Box Lines
	ofSetColor(0);
	ofDrawLine(316, 246, 726, 246);
	ofDrawLine(316, 294, 726, 294);

	//Middle Box Lines

	ofDrawLine(316, 426, 726, 426);
	ofDrawLine(316, 460, 726, 460);
	ofDrawLine(316, 494, 726, 494);

	//Bottom Box Lines

	ofDrawLine(316, 650, 726, 650);
}
