#include "ofMain.h"

#include "Space.h"

Space::Space(int x, int y, int w, int h) {
    //ctor
    mBounds.x = x;
    mBounds.y = y;
    mBounds.width = w;
    mBounds.height = h;
}

Space::~Space() {
    //dtor
}

void Space::draw() {
    ofSetColor(200,200,200);
    ofFill();
    ofRectRounded(mBounds,5);
    ofPushMatrix();
    // Do stuff
    ofPopMatrix();
}
