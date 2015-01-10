#include "TemplateMethod.h"
#include <iostream>

namespace TemplateMethod
{
    void AbstractInstall::TemplateMethod()
    {
        Step1();
        Step2();
        Step3();
        Step4();
        Step5();
    }

    void Install1::Step1()
    {
        std::cout<<"Install1::Step1"<<std::endl;
    }

    void Install1::Step2()
    {
        std::cout<<"Install1::Step2"<<std::endl;
    }

    void Install1::Step3()
    {
        std::cout<<"Install1::Step3"<<std::endl;
    }

    void Install1::Step4()
    {
        std::cout<<"Install1::Step4"<<std::endl;
    }

    void Install1::Step5()
    {
        std::cout<<"Install1::Step5"<<std::endl;
    }

    void Install2::Step1()
    {
        std::cout<<"Install2::Step1"<<std::endl;
    }

    void Install2::Step2()
    {
        std::cout<<"Install2::Step2"<<std::endl;
    }

    void Install2::Step3()
    {
        std::cout<<"Install2::Step3"<<std::endl;
    }

    void Install2::Step4()
    {
        std::cout<<"Install2::Step4"<<std::endl;
    }

    void Install2::Step5()
    {
        std::cout<<"Install2::Step5"<<std::endl;
    }

    void TestTemplateMethod()
    {
        std::cout<<"----------Test TemplateMethod----------"<<std::endl;
        AbstractInstall* install=new Install1;
        install->TemplateMethod();

        install=new Install2;
        install->TemplateMethod();
    }
}
