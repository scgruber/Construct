#include "ofMain.h"
#include "../ConstructApp.h"
#include "../objects/ConstructedPoint.h"

#include "PointTool.h"

extern ConstructApp* gApp;

PointTool::PointTool()
{
    //ctor
}

PointTool::~PointTool()
{
    //dtor
}

void PointTool::setUp()
{
    ConstructedPoint* newPoint = new ConstructedPoint();
    newPoint->placeArbitrary();
    gApp->mSpace->insertObject(newPoint);
    printf("Inserted new point\n");
    gApp->mToolbar->resetActiveTool();
}

void PointTool::handleLeftClick()
{

}

void PointTool::setDown()
{

}

void PointTool::drawButton()
{
    ofSetColor(5,5,5);
    ofFill();
    ofCircle(15,15,5);
}
