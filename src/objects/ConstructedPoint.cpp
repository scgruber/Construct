#include "ofMain.h"

#include "ConstructedPoint.h"

ConstructedPoint::ConstructedPoint() {
    //ctor
    mX = 0;
    mY = 0;
}

ConstructedPoint::~ConstructedPoint() {
    //dtor
}

void ConstructedPoint::draw() {
    ofSetColor(5,5,5);
    ofFill();
    ofCircle(mX, mY, mcRadius);
}

void ConstructedPoint::placeArbitrary() {
    return;
}
