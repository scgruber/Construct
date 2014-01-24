#include "ofMain.h"

#include "../ConstructApp.h"
#include "../objects/ConstructedLine.h"
#include "LineTool.h"

extern ConstructApp* gApp;

LineTool::LineTool()
{
    //ctor
}

LineTool::~LineTool()
{
    //dtor
}

void LineTool::setUp()
{
    ConstructedLine* newLine = new ConstructedLine();
    newLine->placeArbitrary();
    gApp->mSpace->insertObject(newLine);
    printf("Inserted new line (%f,%f) [%f,%f]\n", newLine->mBasePt.x, newLine->mBasePt.y, newLine->mUnitVector.x, newLine->mUnitVector.y);
    gApp->mToolbar->resetActiveTool();
}

void LineTool::handleLeftClick()
{

}

void LineTool::setDown()
{

}

void LineTool::drawButton()
{
    ofSetColor(5,5,5);
    ofSetLineWidth(5);
    ofLine(5,25,25,5);
    ofFill();
    ofCircle(5,25,2.5);
    ofCircle(25,5,2.5);
}

void LineTool::drawTool() {

}

void LineTool::preSelect() {

}
