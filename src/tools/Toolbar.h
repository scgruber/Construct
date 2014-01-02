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
    static const size_t cNumToolSets = 2;
    std::vector<Tool*>* mToolSets;
};

#endif // TOOLBAR_H
