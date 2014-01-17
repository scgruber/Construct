#include "ofMain.h"

#include "ConstructedLine.h"

ConstructedLine::ConstructedLine() {
    //ctor
    mBasePt = ofVec2f(0,0);
    mUnitVector = ofVec2f(1,0);
}

ConstructedLine::~ConstructedLine() {
    //dtor
}

void ConstructedLine::draw() {
    ofVec2f bot = mBasePt - (100*mUnitVector);
    ofVec2f top = mBasePt + (100*mUnitVector);
    ofSetColor(5,5,5);
    ofSetLineWidth(mcWidth);
    ofLine(bot.x, bot.y, top.x, top.y);
}

void ConstructedLine::placeArbitrary() {

}

float ConstructedLine::distanceTo(ConstructedObject* other) {

}
