#include "ofMain.h"

#include "CoincidentTool.h"

CoincidentTool::CoincidentTool() {
    //ctor
}

CoincidentTool::~CoincidentTool() {
    //dtor
}

void CoincidentTool::setUp() {

}

void CoincidentTool::setDown() {

}

void CoincidentTool::handleLeftClick() {

}

void CoincidentTool::drawButton() {
    ofSetColor(224,0,255);
    ofSetLineWidth(2);
    ofNoFill();
    ofCircle(15,15,8);
    ofLine(3,15,27,15);
    ofLine(15,3,15,27);
}

void CoincidentTool::drawTool() {

}
