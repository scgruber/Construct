#include "ofMain.h"

#include "Space.h"

Space::Space() {
    //ctor
}

Space::~Space() {
    //dtor
}

void Space::draw() {
    ofSetColor(200,200,200);
    ofFill();
    ofRectRounded(20,20,mWidth,mHeight,5);
    ofPushMatrix();
    // Do stuff
    ofPopMatrix();
}
