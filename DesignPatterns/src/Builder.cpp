#include "Builder.h"
#include <iostream>

namespace Builder
{
    Product::Product()
    {
    }

    Product::Product(std::string name)
        : productName(name)
    {
    }
    void Product::AddPart(std::string part)
    {
        if(part!="")
        {
            parts.push_back(part);
        }
    }

    void Product::Show()
    {
        std::list<std::string>::iterator it;
        std::cout<<"Product name="<<productName<<std::endl;
        std::cout<<"Product parts=";
        for(it=parts.begin(); it!=parts.end(); ++it)
        {
            std::cout<<*it<<" ";
        }
        std::cout<<std::endl;
    }

    ConcreteBuilder::ConcreteBuilder()
    {
        product=new Product();
    }

    ConcreteBuilder::~ConcreteBuilder()
    {
        if(product!=NULL)
        {
            delete product;
            product=NULL;
        }
    }

    void ConcreteBuilder::Buildpart1()
    {
        std::cout<<"Build part1"<<std::endl;
        product->AddPart("part1");
    }

    void ConcreteBuilder::Buildpart2()
    {
        std::cout<<"Build part2"<<std::endl;
        product->AddPart("part2");
    }

    Product* ConcreteBuilder::GetProduct()
    {
        return product;
    }

    void Director::Construct(Builder* builder)
    {
        builder->Buildpart1();
        builder->Buildpart2();
    }

    void TestBuilder()
    {
        std::cout<<"----------Test Builder----------"<<std::endl;
        Director director;
        Builder* builder=new ConcreteBuilder;
        director.Construct(builder);
        Product* product=builder->GetProduct();
        product->Show();
    }
}

