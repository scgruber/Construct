#include "ofMain.h"
#include "../ConstructApp.h"

#include "ConstructedPoint.h"
#include "ConstructedLine.h"

extern ConstructApp* gApp;

ConstructedPoint::ConstructedPoint() {
    //ctor
    mPos = ofVec2f(0,0);
}

ConstructedPoint::~ConstructedPoint() {
    //dtor
}

void ConstructedPoint::draw() {
    ofSetColor(5,5,5);
    ofFill();
    ofCircle(mPos.x, mPos.y, mcRadius);
}

void ConstructedPoint::placeArbitrary() {
    while (true) {
        ofVec2f best = mPos;
        ofVec2f orig = mPos;
        float bestD = 0.0f;

        // Evaluate candidate points
        ofVec2f candidates[4] = {   orig + ofVec2f(5,0),
                                    orig + ofVec2f(0,5),
                                    orig - ofVec2f(5,0),
                                    orig - ofVec2f(0,5) };
        int randOffset = (int) ofRandom(4);
        for (int iCandidate = 0; iCandidate < 4; iCandidate++) {
            mPos = candidates[(iCandidate+randOffset)%4];
            float leastD = numeric_limits<float>::infinity();
            for (std::vector<ConstructedObject*>::iterator iObject = gApp->mSpace->mObjects.begin();
                    iObject != gApp->mSpace->mObjects.end(); iObject++) {
                float dist = this->distanceTo(*iObject);
                leastD = min(leastD, dist);
            }
            // Break ties randomly
            if ((leastD > bestD) || ((abs(leastD-bestD) < 0.001f) && (ofRandomf() < 0.0f))) {
                bestD = leastD;
                best = mPos;
            }
        }

        if (bestD == 0.0f) {
            // Stabilized
            mPos = orig;
            return;
        } else if (bestD >= 25.0f) {
            // Distance above threshold
            mPos = best;
            return;
        }
    }
}

float ConstructedPoint::distanceTo(ConstructedObject* other) {
    // Try ConstructedPoint
    ConstructedPoint* otherPt = dynamic_cast<ConstructedPoint*>(other);
    if (otherPt != NULL) {
        return ofDist(mPos.x, mPos.y, otherPt->mPos.x, otherPt->mPos.y);
    }

    // Try ConstructedLine
    ConstructedLine* otherLine = dynamic_cast<ConstructedLine*>(other);
    if (otherLine != NULL) {
        ofVec2f p = mPos;
        ofVec2f a = otherLine->mBasePt;
        ofVec2f n = otherLine->mUnitVector;
        return ((a-p) - (((a-p).dot(n))*n)).length();
    }

    // Unable to match to an object type
    return nanf("");
}
