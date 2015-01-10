#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

namespace AbstractFactory
{
    class ICar
    {
    public:
        virtual void Display()=0;
        virtual ~ICar();
    };

    class CivilianCar : public ICar
    {
    public:
        virtual void Display();
    };

    class MilitaryCar : public ICar
    {
    public:
        virtual void Display();
    };

    class IBus
    {
    public:
        virtual void Display()=0;
        virtual ~IBus();
    };

    class CivilianBus : public IBus
    {
    public:
        virtual void Display();
    };

    class MilitaryBus : public IBus
    {
    public:
        virtual void Display();
    };

    class IFactory
    {
    public:
        virtual ICar* CreateCar()=0;
        virtual IBus* CreateBus()=0;
    };

    class CivilianFactory : public IFactory
    {
    public:
        virtual ICar* CreateCar();
        virtual IBus* CreateBus();
    };

    class MilitaryFactory : public IFactory
    {
    public:
        virtual ICar* CreateCar();
        virtual IBus* CreateBus();
    };

    void TestAbstractFactory();
}


#endif // ABSTRACTFACTORY_H
