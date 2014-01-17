#ifndef CONSTRUCTEDPOINT_H
#define CONSTRUCTEDPOINT_H

#include "ConstructedObject.h"


class ConstructedPoint : public ConstructedObject
{
    public:
        ConstructedPoint();
        virtual ~ConstructedPoint();

        void draw();
        void placeArbitrary();
        float distanceTo(ConstructedObject* other);

        ofVec2f mPos;
    protected:
    private:
        const static int mcRadius = 2.5;
};

#endif // CONSTRUCTEDPOINT_H
