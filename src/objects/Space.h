#ifndef SPACE_H
#define SPACE_H

#include "ConstructedObject.h"


class Space
{
    public:
        Space(int x, int y, int w, int h);
        virtual ~Space();

        void draw();
        void insertObject(ConstructedObject* obj);
        void deleteObject(ConstructedObject* obj);

        ofRectangle mBounds;
    protected:
    private:
        std::vector<ConstructedObject*> mObjects;
};

#endif // SPACE_H
