#ifndef CONSTRUCTEDOBJECT_H
#define CONSTRUCTEDOBJECT_H


class ConstructedObject
{
    public:
        virtual void draw() = 0;
        virtual void placeArbitrary() = 0;
        virtual float distanceTo(ConstructedObject* other) = 0;
        virtual bool near(ofVec2f pt) = 0;
        virtual void drawHighlight(ofColor color) = 0;
    protected:
    private:
};

#endif // CONSTRUCTEDOBJECT_H
