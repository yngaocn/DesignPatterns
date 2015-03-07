#include "ChainOfResponsibility.h"
#include <iostream>

namespace ChainOfResponsibility
{

PurchaseRequest::PurchaseRequest(int number, double price)
    : _number(number)
    , _price(price)
{
}

PurchaseRequest::~PurchaseRequest()
{
}

double PurchaseRequest::GetAccount()
{
    return _number*_price;
}

Approver::Approver(std::string name, Approver* successor)
    : _name(name)
    , _successor(successor)
{
}

Approver::~Approver()
{
}

Director::Director(std::string name, Approver* successor)
    : Approver(name, successor)
{
}

Director::~Director()
{
}

void Director::HandleRequest(PurchaseRequest* request)
{
    if(NULL!=request)
    {
        if(request->GetAccount()<10000.0)
        {
            std::cout<<"Director "<<_name<<" handle request "<<request->GetAccount()<<std::endl;
        }
        else
        {
            _successor->HandleRequest(request);
        }
    }
}

VicePresident::VicePresident(std::string name, Approver* successor)
    : Approver(name, successor)
{
}

VicePresident::~VicePresident()
{
}

void VicePresident::HandleRequest(PurchaseRequest* request)
{
    if(NULL!=request)
    {
        if(request->GetAccount()<100000.0)
        {
            std::cout<<"VicePresident "<<_name<<" handle request "<<request->GetAccount()<<std::endl;
        }
        else
        {
            _successor->HandleRequest(request);
        }
    }
}

President::President(std::string name, Approver* successor)
    : Approver(name, successor)
{
}

President::~President()
{
}

void President::HandleRequest(PurchaseRequest* request)
{
    if(NULL!=request)
    {
        if(request->GetAccount()<1000000.0)
        {
            std::cout<<"President "<<_name<<" handle request "<<request->GetAccount()<<std::endl;
        }
        else
        {
            std::cout<<"Request "<<request->GetAccount()<<" requires an executive meeting."<<std::endl;
        }
    }
}

void TestChainOfResponsibility()
{
    std::cout<<"----------Test Chain of Responsibility----------"<<std::endl;
    President president("Mark", NULL);
    VicePresident vicepresident("Tom", &president);
    Director director("XiaoMing", & vicepresident);

    PurchaseRequest purchase_request(10000, 500);
    director.HandleRequest(&purchase_request);
}

}
