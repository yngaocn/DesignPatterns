#ifndef BUILDER_H
#define BUILDER_H

#include <list>
#include <string>

namespace Builder
{
    class Product
    {
    public:
        Product();
        Product(std::string name);
        void AddPart(std::string part);
        void Show();
    private:
        std::string productName;
        std::list<std::string> parts;
    };

    class Builder
    {
    public:
        virtual void Buildpart1()=0;
        virtual void Buildpart2()=0;
        virtual Product* GetProduct()=0;
    };

    class ConcreteBuilder : public Builder
    {
    public:
        ConcreteBuilder();
        virtual ~ConcreteBuilder();
        virtual void Buildpart1();
        virtual void Buildpart2();
        virtual Product* GetProduct();
    private:
        Product* product;
    };

    class Director
    {
    public:
        void Construct(Builder* builder);
    };

    void TestBuilder();
}

#endif // BUILDER_H
