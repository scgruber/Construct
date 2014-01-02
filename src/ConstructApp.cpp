#include "ConstructApp.h"
#include "tools/Toolbar.h"

//--------------------------------------------------------------
void ConstructApp::setup() {
    m_toolbar = new Toolbar();

    // Pretty Graphics Things
    ofEnableSmoothing();
}

//--------------------------------------------------------------
void ConstructApp::update() {

}

//--------------------------------------------------------------
void ConstructApp::draw() {
    ofBackground(30,30,30);
    m_toolbar->draw();
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
