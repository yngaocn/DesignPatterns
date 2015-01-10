#ifndef SIMPLEFACTORY_H
#define SIMPLEFACTORY_H

#include <string>
#include <iostream>

namespace SimpleFactory
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

    class SimpleFactory
    {
    public:
        SimpleFactory();
        virtual ~SimpleFactory();
        static IProduct* CreateProduct(std::string productName);

    protected:
    private:
    };

    void TestSimpleFactory();
}

#endif // SIMPLEFACTORY_H
