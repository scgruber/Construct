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
    while (true) {
        int oldX = mX;
        int oldY = mY;
        float bestD = 0.0f;
        // Generate candidate points,
        // choose one with the farthest nearest neighbor,
        // repeat until stable or distance > 10
        if (((oldX == mX) && (oldY == mY)) || bestD > 10.0f) {
            return;
        }
    }
}

float ConstructedPoint::distanceTo(ConstructedObject* other) {
    // Try ConstructedPoint
    ConstructedPoint* otherPt = dynamic_cast<ConstructedPoint*>(other);
    if (otherPt != NULL) {
        return ofDist(mX, mY, otherPt->mX, otherPt->mY);
    }

    // Unable to match to an object type
    return nanf("");
}
