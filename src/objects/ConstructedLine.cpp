#include "ofMain.h"
#include "../ConstructApp.h"

#include "ConstructedLine.h"
#include "ConstructedPoint.h"

extern ConstructApp* gApp;

ConstructedLine::ConstructedLine() {
    //ctor
    mBasePt = ofVec2f(ofRandom(-100,100),ofRandom(-100,100));
    mUnitVector = ofVec2f(ofRandom(-100,100),ofRandom(-100,100)).getNormalized();
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
    while(true) {
        ofVec2f bestPt = mBasePt;
        ofVec2f origPt = mBasePt;
        ofVec2f bestVec = mUnitVector;
        ofVec2f origVec = mUnitVector;
        float bestD = 0.0f;

        std::pair<ofVec2f,ofVec2f> candidates[12] =
            {   std::pair<ofVec2f,ofVec2f>(origPt + ofVec2f(5,0), origVec.getRotated(5)),
                std::pair<ofVec2f,ofVec2f>(origPt + ofVec2f(5,0), origVec.getRotated(0)),
                std::pair<ofVec2f,ofVec2f>(origPt + ofVec2f(5,0), origVec.getRotated(-5)),
                std::pair<ofVec2f,ofVec2f>(origPt + ofVec2f(0,5), origVec.getRotated(5)),
                std::pair<ofVec2f,ofVec2f>(origPt + ofVec2f(0,5), origVec.getRotated(0)),
                std::pair<ofVec2f,ofVec2f>(origPt + ofVec2f(0,5), origVec.getRotated(-5)),
                std::pair<ofVec2f,ofVec2f>(origPt - ofVec2f(5,0), origVec.getRotated(5)),
                std::pair<ofVec2f,ofVec2f>(origPt - ofVec2f(5,0), origVec.getRotated(0)),
                std::pair<ofVec2f,ofVec2f>(origPt - ofVec2f(5,0), origVec.getRotated(-5)),
                std::pair<ofVec2f,ofVec2f>(origPt - ofVec2f(0,5), origVec.getRotated(5)),
                std::pair<ofVec2f,ofVec2f>(origPt - ofVec2f(0,5), origVec.getRotated(0)),
                std::pair<ofVec2f,ofVec2f>(origPt - ofVec2f(0,5), origVec.getRotated(-5))
            };
        int randOffset = (int) ofRandom(12);
        for (int iCandidate = 0; iCandidate < 12; iCandidate++) {
            mBasePt = candidates[(iCandidate+randOffset)%12].first;
            mUnitVector = candidates[(iCandidate+randOffset)%12].second;
            float leastD = numeric_limits<float>::infinity();
            for (std::vector<ConstructedObject*>::iterator iObject = gApp->mSpace->mObjects.begin();
                    iObject != gApp->mSpace->mObjects.end(); iObject++) {
                float dist = this->distanceTo(*iObject);
                leastD = min(leastD, dist);
            }
            // Break ties randomly
            if ((leastD > bestD) || ((abs(leastD-bestD) < 0.001f) && (ofRandomf() < 0.0f))) {
                bestD = leastD;
                bestPt = mBasePt;
                bestVec = mUnitVector;
            }
        }

        if (bestD == 0.0f) {
            // Stabilized
            mBasePt = origPt;
            mUnitVector = origVec;
            return;
        } else if (bestD >= 25.0f) {
            // Distance above threshold
            mBasePt = bestPt;
            mUnitVector = bestVec;
            return;
        }
    }
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

bool ConstructedLine::near(ofVec2f pt) {
    ofVec2f a = mBasePt;
    ofVec2f n = mUnitVector;
    return (((a-pt) - (((a-pt).dot(n))*n)).length() < 10.0f);
}

void ConstructedLine::drawHighlight(ofColor color) {
    ofPushMatrix();
    ofMultMatrix(gApp->mSpace->mWorldMatrix);
    ofVec2f bot = mBasePt - (250*mUnitVector);
    ofVec2f top = mBasePt + (250*mUnitVector);
    ofSetColor(color, 128);
    ofSetLineWidth(mcWidth+6);
    ofLine(bot.x, bot.y, top.x, top.y);
    ofPopMatrix();
}
