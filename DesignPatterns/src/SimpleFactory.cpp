#include "SimpleFactory.h"

namespace SimpleFactory
{
    SimpleFactory::SimpleFactory()
    {
        //ctor
    }

    SimpleFactory::~SimpleFactory()
    {
        //dtor
    }

    IProduct* SimpleFactory::CreateProduct(std::string productName)
    {
        IProduct* product=NULL;
        if(productName=="A")
        {
            product=new ProductA;
        }
        else if(productName=="B")
        {
            product=new ProductB;
        }
        return product;
    }

    void ProductA::Func()
    {
        std::cout<<"ProductA::Func()"<<std::endl;
    }

    void ProductB::Func()
    {
        std::cout<<"ProductB::Func()"<<std::endl;
    }

    void TestSimpleFactory()
    {
        std::cout<<"----------Test SimpleFactory----------"<<std::endl;
        IProduct* product=SimpleFactory::CreateProduct("A");
        product->Func();
    }
}
