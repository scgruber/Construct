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
    ofVec2f mouse = ofVec2f(ofGetMouseX(), ofGetMouseY());
    if (gApp->mSpace->mBounds.inside(mouse)) {
        ConstructedObject* underObject = gApp->mSpace->getObjectUnderCursor();
        if (underObject != NULL) {
            gApp->mSpace->mSelection.clear();
            gApp->mSpace->mSelection.push_back(underObject);
        }
    }
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

}

void SelectionTool::preSelect() {
    ofVec2f mouse = ofVec2f(ofGetMouseX(), ofGetMouseY());
    if (gApp->mSpace->mBounds.inside(mouse)) {
        ConstructedObject* underObject = gApp->mSpace->getObjectUnderCursor();
        if (underObject != NULL) {
            gApp->mSpace->mPreSelection.push_back(underObject);
        }
    }
}
