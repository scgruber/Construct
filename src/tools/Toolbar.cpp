#include "ofMain.h"
#include "Toolbar.h"

Toolbar::Toolbar() {
    // Initialize toolsets
    mToolSets = (std::vector<Tool*>*) calloc(cNumToolSets, sizeof(std::vector<Tool*>*));
}

Toolbar::~Toolbar() {
    //dtor
}

void Toolbar::draw() {
    ofSetColor(200,200,200);
    ofRectRounded(20,20,40,300,5);
}

bool Toolbar::registerTool(int toolGroup, Tool* tool) {
    if ((0 <= toolGroup) && (toolGroup < cNumToolSets)) {
        // Group index is valid
        // Add the tool
        return true;
    } else {
        return false;
    }
}
