#include "ofMain.h"

#include "Space.h"

Space::Space(int x, int y, int w, int h) {
    //ctor
    mBounds.x = x;
    mBounds.y = y;
    mBounds.width = w;
    mBounds.height = h;
}

Space::~Space() {
    //dtor
}

void Space::draw() {
    ofSetColor(200,200,200);
    ofFill();
    ofRectRounded(mBounds,5);
    ofPushMatrix();
    // Do stuff
    ofPopMatrix();
}

void Space::insertObject(ConstructedObject* obj) {
    mObjects.push_back(obj);
}

void Space::deleteObject(ConstructedObject* obj) {
    for (std::vector<ConstructedObject*>::iterator iObject = mObjects.begin();
            iObject != mObjects.end(); iObject++) {
        if (*iObject == obj) {
            mObjects.erase(iObject);
            return;
        }
    }
}
