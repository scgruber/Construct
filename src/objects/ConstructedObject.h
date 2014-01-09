#ifndef CONSTRUCTEDOBJECT_H
#define CONSTRUCTEDOBJECT_H


class ConstructedObject
{
    public:
        virtual void draw() = 0;
        virtual void placeArbitrary() = 0;
        virtual float distanceTo(ConstructedObject* other) = 0;
    protected:
    private:
};

#endif // CONSTRUCTEDOBJECT_H