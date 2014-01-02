#ifndef POINTTOOL_H
#define POINTTOOL_H

#include "Tool.h"


class PointTool : public Tool
{
    public:
        PointTool();
        virtual ~PointTool();

        void setUp();
        void handleLeftClick();
        void setDown();

        void drawButton();
    protected:
    private:
};

#endif // POINTTOOL_H
