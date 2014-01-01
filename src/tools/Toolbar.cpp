#include "ofMain.h"
#include "Toolbar.h"

Toolbar::Toolbar() {
    //ctor
}

Toolbar::~Toolbar() {
    //dtor
}

void Toolbar::draw() {
    ofSetColor(200,200,200);
    ofRectRounded(20,20,40,300,5);
}
