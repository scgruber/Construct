#include "ofMain.h"

#include "ConstructedLine.h"

ConstructedLine::ConstructedLine() {
    //ctor
    mIntercept = 0;
    mSlope = 1.0f;
}

ConstructedLine::~ConstructedLine() {
    //dtor
}

void ConstructedLine::draw() {
    ofVec2f bot = ofVec2f(-10, mIntercept-(10*mSlope));
    ofVec2f top = ofVec2f( 10, mIntercept+(10*mSlope));
    ofSetColor(5,5,5);
    ofSetLineWidth(mcWidth);
    ofLine(bot.x, bot.y, top.x, top.y);
}

void ConstructedLine::placeArbitrary() {

}

float ConstructedLine::distanceTo(ConstructedObject* other) {

}
