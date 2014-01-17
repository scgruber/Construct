#include "ofMain.h"

#include "ConstructedLine.h"
#include "ConstructedPoint.h"

ConstructedLine::ConstructedLine() {
    //ctor
    mBasePt = ofVec2f(0,0);
    mUnitVector = ofVec2f(1,0);
}

ConstructedLine::~ConstructedLine() {
    //dtor
}

void ConstructedLine::draw() {
    ofVec2f bot = mBasePt - (250*mUnitVector);
    ofVec2f top = mBasePt + (250*mUnitVector);
    ofSetColor(5,5,5);
    ofSetLineWidth(mcWidth);
    ofLine(bot.x, bot.y, top.x, top.y);
}

void ConstructedLine::placeArbitrary() {

}

float ConstructedLine::distanceTo(ConstructedObject* other) {
    // Try ConstructedPoint
    ConstructedPoint* otherPt = dynamic_cast<ConstructedPoint*>(other);
    if (otherPt != NULL) {
        ofVec2f p = otherPt->mPos;
        ofVec2f a = mBasePt;
        ofVec2f n = mUnitVector;
        return ((a-p) - (((a-p).dot(n))*n)).length();
    }

    // Try ConstructedLine
    ConstructedLine* otherLine = dynamic_cast<ConstructedLine*>(other);
    if (otherLine != NULL) {
        float d = mUnitVector.dot(otherLine->mUnitVector);
        if (abs(d) == 1.0f) {
            ofVec2f p = otherLine->mBasePt;
            ofVec2f a = mBasePt;
            ofVec2f n = mUnitVector;
            return ((a-p) - (((a-p).dot(n))*n)).length();
        } else {
            return 0.0f;
        }
    }

    // Unable to match to an object type
    return nanf("");
}
