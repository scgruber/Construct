#ifndef LINETOOL_H
#define LINETOOL_H

#include "Tool.h"


class LineTool : public Tool
{
    public:
        LineTool();
        virtual ~LineTool();

        void setUp();
        void handleLeftClick();
        void setDown();

        void drawButton();
        void drawTool();
        void preSelect();
    protected:
    private:
};

#endif // LINETOOL_H
