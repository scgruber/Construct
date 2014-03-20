#include "ofMain.h"
#include "SelectionTool.h"
#include "PointTool.h"
#include "LineTool.h"
#include "CoincidentTool.h"

#include "Toolbar.h"

Toolbar::Toolbar() {
    // Initialize toolsets
    for (int iToolSet = 0; iToolSet < mcNumToolSets; iToolSet++) {
        mToolSets[iToolSet] = new std::vector<Tool*>();
    }
    // Register tools
    registerTool(0,new SelectionTool());

    registerTool(1,new PointTool());
    registerTool(1,new LineTool());

    registerTool(2,new CoincidentTool());

    // Set active tool to be 0,0
    mActiveTool.first = 0;
    mActiveTool.second = 0;
}

Toolbar::~Toolbar() {
    //dtor
}

void Toolbar::handleLeftClick(int x, int y) {
    printf("Toolbar coords: (%d,%d)\n", x, y);
    int iToolSet = 0;
    while ((y >= 0) && (iToolSet < mcNumToolSets)) {
        y -= 5;
        if ((y / 30) < mToolSets[iToolSet]->size()) {
            mActiveTool.first = iToolSet;
            mActiveTool.second = y/30;
            printf("Activating tool (%d,%d)\n", mActiveTool.first, mActiveTool.second);
            mToolSets[mActiveTool.first]->at(mActiveTool.second)->setUp();
            return;
        } else {
            y -= mToolSets[iToolSet]->size() * 30;
        }
        iToolSet++;
    }
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
            if ((iToolSet == mActiveTool.first) && (iTool == mActiveTool.second)) {
                ofSetColor(80,180,20);
                ofFill();
                ofRectRounded(0,0,30,30,2);
            }
            mToolSets[iToolSet]->at(iTool)->drawButton();
            ofTranslate(0,30,0);
        }
    }
    ofPopMatrix();
}

bool Toolbar::registerTool(int toolGroup, Tool* tool) {
    if ((0 <= toolGroup) && (toolGroup < mcNumToolSets)) {
        // Group index is valid.
        // Increase the toolbar height to accomodate the tool
        if (mToolSets[toolGroup]->empty()) {
            mHeight += 5;
        }
        mHeight += 30;
        // Add the tool.
        mToolSets[toolGroup]->push_back(tool);
        return true;
    } else {
        // Group index out of bounds. Registration fails.
        return false;
    }
}

void Toolbar::resetActiveTool() {
    mToolSets[mActiveTool.first]->at(mActiveTool.second)->setDown();
    mActiveTool.first = 0;
    mActiveTool.second = 0;
}

Tool* Toolbar::getActiveTool() {
    return mToolSets[mActiveTool.first]->at(mActiveTool.second);
}
