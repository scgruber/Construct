#include "ofMain.h"
#include "ConstructApp.h"

ConstructApp* gApp;

//========================================================================
int main( ) {
	ofSetupOpenGL(1000,750,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	gApp = new ConstructApp();

	ofRunApp(gApp);

}
