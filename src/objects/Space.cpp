#include "ofMain.h"
#include "ConstructedObject.h"

#include "Space.h"

Space::Space(int x, int y, int w, int h) {
    //ctor
    mBounds.x = x;
    mBounds.y = y;
    mBounds.width = w;
    mBounds.height = h;

    mWorldMatrix.makeTranslationMatrix(x + (w/2), y + (h/2), 0);
}

Space::~Space() {
    //dtor
}

void Space::draw() {
    ofSetColor(200,200,200);
    ofFill();
    ofRectRounded(mBounds,5);
    ofPushMatrix();
    ofMultMatrix(mWorldMatrix);
    for (std::vector<ConstructedObject*>::iterator iObject = mObjects.begin();
            iObject != mObjects.end(); iObject++) {
        (*iObject)->draw();
    }
    ofPopMatrix();
}

void Space::insertObject(ConstructedObject* obj) {
    mObjects.push_back(obj);
    obj->placeArbitrary();
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

ConstructedObject* Space::getObjectUnderCursor() {
    ofVec2f mouse = ofVec2f(ofGetMouseX(), ofGetMouseY());
    if (mBounds.inside(mouse)) {
        ofVec2f worldMouse = mouse - mBounds.getCenter(); // todo: better screen->world conversion

        for (std::vector<ConstructedObject*>::iterator iObject = mObjects.begin();
                iObject != mObjects.end(); iObject++) {
            if ((*iObject)->near(worldMouse)) {
                return *iObject;
            }
        }
    }
    return NULL;
}
