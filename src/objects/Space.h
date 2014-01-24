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
        ConstructedObject* getObjectUnderCursor();

        ofMatrix4x4 mWorldMatrix;

        ofRectangle mBounds;
        std::vector<ConstructedObject*> mObjects;
    protected:
    private:
};

#endif // SPACE_H
