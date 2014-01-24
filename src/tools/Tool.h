#ifndef TOOL_H
#define TOOL_H


class Tool
{
    public:
        virtual void setUp() = 0;
        virtual void handleLeftClick() = 0;
        virtual void setDown() = 0;

        virtual void drawButton() = 0;
        virtual void drawTool() = 0;
        virtual void preSelect() = 0;
    protected:
    private:
};

#endif // TOOL_H
