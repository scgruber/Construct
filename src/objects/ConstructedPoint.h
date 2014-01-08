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
    protected:
    private:
        int mX;
        int mY;
        const static int mcRadius = 2.5;
};

#endif // CONSTRUCTEDPOINT_H
