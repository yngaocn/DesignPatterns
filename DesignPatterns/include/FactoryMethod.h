#ifndef FACTORYMETHOD_H
#define FACTORYMETHOD_H

#include <iostream>

namespace FactoryMethod
{
    class IProduct
    {
    public:
        virtual void Func()=0;
    };

    class ProductA : public IProduct
    {
    public:
        virtual void Func();
    };

    class ProductB : public IProduct
    {
    public:
        virtual void Func();
    };

    class IFactory
    {
    public:
        virtual IProduct* CreateProduct()=0;
    };

    class FactoryA : public IFactory
    {
    public:
        virtual IProduct* CreateProduct();
    };

    class FactoryB : public IFactory
    {
    public:
        virtual IProduct* CreateProduct();
    };

    void TestFactoryMethod();
}

#endif // FACTORYMETHOD_H
