#include "AbstractFactory.h"
#include <iostream>

namespace AbstractFactory
{
    ICar::~ICar()
    {
    }

    IBus::~IBus()
    {
    }

    void CivilianCar::Display()
    {
        std::cout<<"CivilianCar"<<std::endl;
    }

    void MilitaryCar::Display()
    {
        std::cout<<"MilitaryCar"<<std::endl;
    }

    void CivilianBus::Display()
    {
        std::cout<<"CivilianBus"<<std::endl;
    }

    void MilitaryBus::Display()
    {
        std::cout<<"MilitaryBus"<<std::endl;
    }

    ICar* CivilianFactory::CreateCar()
    {
        return new CivilianCar;
    }

    IBus* CivilianFactory::CreateBus()
    {
        return new CivilianBus;
    }

    ICar* MilitaryFactory::CreateCar()
    {
        return new MilitaryCar;
    }

    IBus* MilitaryFactory::CreateBus()
    {
        return new MilitaryBus;
    }

    void TestAbstractFactory()
    {
        std::cout<<"----------Test AbstractFactory----------"<<std::endl;
        CivilianFactory civilianFactory;
        ICar* civilianCar=civilianFactory.CreateCar();
        IBus* civilianBus=civilianFactory.CreateBus();

        MilitaryFactory militaryFactory;
        ICar* militaryCar=militaryFactory.CreateCar();
        IBus* militaryBus=militaryFactory.CreateBus();

        civilianCar->Display();
        civilianBus->Display();
        militaryCar->Display();
        militaryBus->Display();

        delete civilianCar;
        delete civilianBus;
        delete militaryCar;
        delete militaryBus;
    }
}

