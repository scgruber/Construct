#ifndef SPACE_H
#define SPACE_H


class Space
{
    public:
        Space();
        virtual ~Space();

        void draw();
    protected:
    private:
        int mWidth = 900;
        int mHeight = 500;
};

#endif // SPACE_H
