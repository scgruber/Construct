#include "ofMain.h"
#include "SelectionTool.h"

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
    // Assumes that we have been translated and can draw in the next 30x30 px
    ofSetColor(5,5,5);
    ofBeginShape();
        ofVertex(5,5);
        ofVertex(25,14);
        ofVertex(16,16);
    ofEndShape();
    ofFill();
    ofBeginShape();
        ofVertex(16,16);
        ofVertex(14,25);
        ofVertex(5,5);
    ofEndShape();
    ofFill();
}
