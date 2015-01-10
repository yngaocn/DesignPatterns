#include "Facade.h"
#include <iostream>

namespace Facade
{
    void SubSystem::Function1()
    {
        std::cout<<"SubSystem::Function1"<<std::endl;
    }

    void SubSystem::Function2()
    {
        std::cout<<"SubSystem::Function2"<<std::endl;
    }

    void Facade::Function()
    {
        subsystem.Function1();
        subsystem.Function2();
    }

    void TestFacade()
    {
        std::cout<<"----------Test Facade----------"<<std::endl;
        Facade facade;
        facade.Function();
    }
}

