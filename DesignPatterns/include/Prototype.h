#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <iostream>
#include <string>
#include <string.h>

namespace Prototype
{
    class ICloneable
    {
    public:
        virtual ICloneable* Clone()=0;
        virtual void Disp()=0;
    };

    class Prototype1 : public ICloneable
    {
    public:
        Prototype1();
        Prototype1(const char* data);
        Prototype1(const Prototype1& prototype);
        virtual ~Prototype1();
        virtual ICloneable* Clone();
        virtual void Disp();
    private:
        char* data;
    };

    void TestPrototype();
}


#endif // PROTOTYPE_H
