#ifndef CONSTRUCTEDLINE_H
#define CONSTRUCTEDLINE_H

#include "ConstructedObject.h"


class ConstructedLine : public ConstructedObject
{
    public:
        ConstructedLine();
        virtual ~ConstructedLine();

        void draw();
        void placeArbitrary();
        float distanceTo(ConstructedObject* other);

        ofVec2f mBasePt;
        ofVec2f mUnitVector;
    protected:
    private:
        const static float mcWidth = 2.5;
};

#endif // CONSTRUCTEDLINE_H
