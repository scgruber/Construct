#include "ofMain.h"
#include "../ConstructApp.h"

#include "CoincidentTool.h"

extern ConstructApp* gApp;

CoincidentTool::CoincidentTool() {
    //ctor
}

CoincidentTool::~CoincidentTool() {
    //dtor
}

void CoincidentTool::setUp() {
    if (gApp->mSpace->mSelection.size() == 1) {
        // Create constraint
        mToolMode = mcWaitingForReferenceMode;
    } else {
        printf("Must select an object first!\n");
        gApp->mToolbar->resetActiveTool();
    }
}

void CoincidentTool::setDown() {
    mToolMode = mcDefaultMode;
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
    ofVec2f mouse = ofVec2f(ofGetMouseX(), ofGetMouseY());
    if (gApp->mSpace->mBounds.inside(mouse)) {

        // Draw constraint icon
        ofSetColor(224,0,255);
        ofSetLineWidth(1);
        ofNoFill();
        ofCircle(mouse, 10);
        ofLine(mouse - ofVec2f(12,0), mouse + ofVec2f(12,0));
        ofLine(mouse - ofVec2f(0,12), mouse + ofVec2f(0,12));

        ConstructedObject* underObject = gApp->mSpace->getObjectUnderCursor();
        if (underObject != NULL) {
            underObject->drawHighlight(ofColor(0,255,0));
        }
    }
}
