#ifndef CONSTRUCTAPP_H
#define CONSTRUCTAPP_H

#include "ofMain.h"
#include "tools/Toolbar.h"
#include "objects/Space.h"

class ConstructApp : public ofBaseApp {

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    Toolbar* mToolbar;
    Space* mSpace;
protected:
private:

};
#endif // CONSTRUCTAPP_H
