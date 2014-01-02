#ifndef TOOLBAR_H
#define TOOLBAR_H

#include "Tool.h"

class Toolbar {
public:
    Toolbar();
    virtual ~Toolbar();

    void draw();

    bool registerTool(int toolGroup, Tool* tool);
protected:
private:
    int mWidth = 40;
    int mHeight = 20;

    std::pair<int,int> mActiveTool;

    static const size_t mcNumToolSets = 2;
    std::vector<Tool*>* mToolSets [mcNumToolSets];
};

#endif // TOOLBAR_H
