#include "Adapter.h"
#include <iostream>

namespace Adapter
{

void Adaptee::SpecialRequest()
{
    std::cout<<"Special request"<<std::endl;
}

Target::~Target()
{
}

void Adapter::Request()
{
    _adaptee.SpecialRequest();
}

void TestAdapter()
{
    std::cout<<"----------Test Adapter----------"<<std::endl;
    Target* target=new Adapter;
    target->Request();
    delete target;
}

}

