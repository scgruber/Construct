#include "ofMain.h"
#include "SelectionTool.h"

#include "Toolbar.h"

Toolbar::Toolbar() {
    // Initialize toolsets
    for (int iToolSet = 0; iToolSet < mcNumToolSets; iToolSet++) {
        mToolSets[iToolSet] = new std::vector<Tool*>();
    }
    // Register tools
    registerTool(0,new SelectionTool());

    // Set active tool to be 0,0
    mActiveTool.first = 0;
    mActiveTool.second = 0;
}

Toolbar::~Toolbar() {
    //dtor
}

void Toolbar::draw() {
    ofSetColor(200,200,200);
    ofFill();
    ofRectRounded(20,20,mWidth,mHeight,5);
    ofPushMatrix();
    ofTranslate(25,25,0);
    for (int iToolSet = 0; iToolSet < mcNumToolSets; iToolSet++) {
        if ((iToolSet != 0) && (mToolSets[iToolSet]->size() != 0)) {
            ofSetColor(100,100,100);
            ofSetLineWidth(1);
            ofLine(2,3,28,3);
            ofTranslate(0,5,0);
        }
        for (int iTool = 0; iTool < mToolSets[iToolSet]->size(); iTool++) {
            mToolSets[iToolSet]->at(iTool)->drawButton();
            ofTranslate(0,30,0);
        }
    }
    ofPopMatrix();
}

bool Toolbar::registerTool(int toolGroup, Tool* tool) {
    if ((0 <= toolGroup) && (toolGroup < mcNumToolSets)) {
        // Group index is valid. Add the tool.
        mToolSets[toolGroup]->push_back(tool);
        // Increase the toolbar height to accomodate the tool
        mHeight += 30;
        return true;
    } else {
        // Group index out of bounds. Registration fails.
        return false;
    }
}
