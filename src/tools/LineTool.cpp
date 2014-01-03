#include "ofMain.h"

#include "LineTool.h"

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
