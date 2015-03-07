#ifndef CHAINOFRESPONSIBILITY_H
#define CHAINOFRESPONSIBILITY_H

#include <string>
#include <cstddef>

namespace ChainOfResponsibility
{

class PurchaseRequest
{
public:
    PurchaseRequest(int number=0, double price=0.0);
    virtual ~PurchaseRequest();
    double GetAccount();

private:
    int _number;
    double _price;
};

class Approver
{
public:
    Approver(std::string name, Approver* successor=NULL);
    virtual ~Approver();
    virtual void HandleRequest(PurchaseRequest* request)=0;

protected:
    Approver* _successor;
    std::string _name;
};

class Director : public Approver
{
public:
    Director(std::string name, Approver* successor);
    virtual ~Director();
    virtual void HandleRequest(PurchaseRequest* request);
};

class VicePresident : public Approver
{
public:
    VicePresident(std::string name, Approver* successor);
    virtual ~VicePresident();
    virtual void HandleRequest(PurchaseRequest* request);
};

class President : public Approver
{
public:
    President(std::string name, Approver* successor);
    virtual ~President();
    virtual void HandleRequest(PurchaseRequest* request);
};

void TestChainOfResponsibility();

};

#endif // CHAINOFRESPONSIBILITY_H
