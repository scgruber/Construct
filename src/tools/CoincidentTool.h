#ifndef COINCIDENTTOOL_H
#define COINCIDENTTOOL_H

#include "Tool.h"


class CoincidentTool : public Tool
{
    public:
        CoincidentTool();
        virtual ~CoincidentTool();

        void setUp();
        void handleLeftClick();
        void setDown();

        void drawButton();
        void drawTool();
    protected:
    private:
        int mcDefaultMode = 0;
        int mcWaitingForReferenceMode = 1;
        int mToolMode;
};

#endif // COINCIDENTTOOL_H
