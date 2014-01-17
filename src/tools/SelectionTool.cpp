#include "ofMain.h"
#include "SelectionTool.h"
#include "../ConstructApp.h"

extern ConstructApp* gApp;

SelectionTool::SelectionTool()
{
    //ctor
}

SelectionTool::~SelectionTool()
{
    //dtor
}

void SelectionTool::setUp()
{

}

void SelectionTool::handleLeftClick()
{

}

void SelectionTool::setDown()
{

}

void SelectionTool::drawButton()
{
    ofSetColor(5,5,5);
    ofFill();
    ofBeginShape();
        ofVertex(5,5);
        ofVertex(25,14);
        ofVertex(16,16);
    ofEndShape();
    ofBeginShape();
        ofVertex(16,16);
        ofVertex(14,25);
        ofVertex(5,5);
    ofEndShape();
}

void SelectionTool::drawTool() {
    ofVec2f mouse = ofVec2f(ofGetMouseX(), ofGetMouseY());
    if (gApp->mSpace->mBounds.inside(mouse)) {
        if (gApp->mSpace->getObjectUnderCursor() != NULL) {
            ofSetColor(0,0,255,128);
        } else {
            ofSetColor(255,0,0,128);
        }
        ofFill();
        ofCircle(mouse.x, mouse.y, 20);
    }
}
