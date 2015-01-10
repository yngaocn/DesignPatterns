#ifndef FACADE_H
#define FACADE_H

namespace Facade
{
    class SubSystem
    {
    public:
        void Function1();
        void Function2();
    };

    class Facade
    {
    public:
        void Function();

    private:
        SubSystem subsystem;
    };

    void TestFacade();
}


#endif // FACADE_H
