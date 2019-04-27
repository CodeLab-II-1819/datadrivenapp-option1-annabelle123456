#include <iostream>
#include "ofMain.h"
#include "ofApp.h"
#include "Header.h"

int main() {
	OfSetupOpenGL(1024, 768, OF_WINDOW);
	//this starts the running of my app 

	ofRunApp(new ofApp());


}