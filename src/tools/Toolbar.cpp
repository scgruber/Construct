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
}

Toolbar::~Toolbar() {
    //dtor
}

void Toolbar::draw() {
    ofSetColor(200,200,200);
    ofRectRounded(20,20,mWidth,mHeight,5);
    ofPushMatrix();
    ofTranslate(25,25,0);
    for (int iToolSet = 0; iToolSet < mcNumToolSets; iToolSet++) {
        for (std::vector<Tool*>::iterator it = mToolSets[iToolSet]->begin();
            it != mToolSets[iToolSet]->end(); it++) {
            (*it)->drawButton();
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
