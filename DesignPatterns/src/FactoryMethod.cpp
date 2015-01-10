#include "FactoryMethod.h"
namespace FactoryMethod
{
    void ProductA::Func()
    {
        std::cout<<"ProductA::Func()"<<std::endl;
    }

    void ProductB::Func()
    {
        std::cout<<"ProductB::Func()"<<std::endl;
    }

    IProduct* FactoryA::CreateProduct()
    {
        return static_cast<IProduct*>(new ProductA);
    }

    IProduct* FactoryB::CreateProduct()
    {
        return static_cast<IProduct*>(new ProductB);
    }

    void TestFactoryMethod()
    {
        std::cout<<"----------Test FactoryMethod----------"<<std::endl;
        IFactory* factory=new FactoryA;
        IProduct* product=factory->CreateProduct();
        product->Func();
    }
}
