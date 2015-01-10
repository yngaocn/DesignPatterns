#ifndef ADAPTER_H
#define ADAPTER_H

namespace Adapter
{

class Adaptee
{
public:
    void SpecialRequest();
};

class Target
{
public:
    virtual void Request()=0;
    virtual ~Target();
};

class Adapter : public Target
{
public:
    virtual void Request();

private:
    Adaptee _adaptee;
};

void TestAdapter();

}

#endif // ADAPTER_H
