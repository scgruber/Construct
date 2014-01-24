#ifndef TOOLBAR_H
#define TOOLBAR_H

#include "Tool.h"

class Toolbar {
public:
    Toolbar();
    virtual ~Toolbar();

    void handleLeftClick(int x, int y);

    void draw();

    bool registerTool(int toolGroup, Tool* tool);
    void resetActiveTool();
    Tool* getActiveTool();
protected:
private:
    int mWidth = 40;
    int mHeight = 5;

    std::pair<int,int> mActiveTool;

    static const size_t mcNumToolSets = 3;
    std::vector<Tool*>* mToolSets [mcNumToolSets];
};

#endif // TOOLBAR_H
