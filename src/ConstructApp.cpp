#include "ConstructApp.h"
#include "tools/Toolbar.h"

//--------------------------------------------------------------
void ConstructApp::setup() {
    mToolbar = new Toolbar();
    mSpace = new Space(75,20,900,500);

    // Pretty Graphics Things
    // ofEnableSmoothing();
}

//--------------------------------------------------------------
void ConstructApp::update() {

}

//--------------------------------------------------------------
void ConstructApp::draw() {
    ofBackground(30,30,30);
    mToolbar->draw();
    mSpace->draw();
}

//--------------------------------------------------------------
void ConstructApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ConstructApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ConstructApp::mouseMoved(int x, int y ) {

}

//--------------------------------------------------------------
void ConstructApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ConstructApp::mousePressed(int x, int y, int button) {
    switch(button) {
    case 0: /* Left */
        if (x < 70) /* Toolbar Region */ {
            mToolbar->handleLeftClick(x-20, y-20);
        }
        break;
    case 1: /* Center */
        break;
    case 2: /* Right */
        break;
    default:
        printf("Received mouse click from button %d, dying!\n", button);
        exit();
    }
}

//--------------------------------------------------------------
void ConstructApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ConstructApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ConstructApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ConstructApp::dragEvent(ofDragInfo dragInfo) {

}
