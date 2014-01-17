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
