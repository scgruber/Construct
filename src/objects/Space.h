#ifndef SPACE_H
#define SPACE_H


class Space
{
    public:
        Space(int x, int y, int w, int h);
        virtual ~Space();

        void draw();

        ofRectangle mBounds;
    protected:
    private:
};

#endif // SPACE_H
