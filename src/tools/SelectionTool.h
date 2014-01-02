#ifndef SELECTIONTOOL_H
#define SELECTIONTOOL_H

#include "Tool.h"


class SelectionTool : public Tool
{
    public:
        SelectionTool();
        virtual ~SelectionTool();

        void setUp();
        void handleLeftClick();
        void setDown();

        void drawButton();
    protected:
    private:
};

#endif // SELECTIONTOOL_H
