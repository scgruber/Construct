#include "ofMain.h"
#include "../ConstructApp.h"

#include "ConstructedPoint.h"

extern ConstructApp* gApp;

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
        int bestX = mX;
        int bestY = mY;
        int origX = mX;
        int origY = mY;
        float bestD = 0.0f;

        // Evaluate candidate points
        ofVec2f candidates[4] = {   ofVec2f(origX+5,origY),
                                    ofVec2f(origX,origY+5),
                                    ofVec2f(origX-5,origY),
                                    ofVec2f(origX,origY-5) };
        for (int iCandidate = 0; iCandidate < 4; iCandidate++) {
            mX = candidates[iCandidate].x;
            mY = candidates[iCandidate].y;
            float leastD = numeric_limits<float>::infinity();
            for (std::vector<ConstructedObject*>::iterator iObject = gApp->mSpace->mObjects.begin();
                    iObject != gApp->mSpace->mObjects.end(); iObject++) {
                float dist = this->distanceTo(*iObject);
                leastD = min(leastD, dist);
            }
            // Break ties randomly
            if ((leastD > bestD) || ((abs(leastD-bestD) < 0.001f) && (ofRandomf() < 0.0f))) {
                bestD = leastD;
                bestX = mX;
                bestY = mY;
            }
        }

        if (bestD == 0.0f) {
            // Stabilized
            mX = origX;
            mY = origY;
            return;
        } else if (bestD >= 25.0f) {
            // Distance above threshold
            mX = bestX;
            mY = bestY;
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
