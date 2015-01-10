#ifndef PROXY_H
#define PROXY_H
#include <iostream>

namespace Proxy
{
    class Subject
    {
    public:
        virtual ~Subject();
        virtual void Request()=0;
    };

    class RealSubject : public Subject
    {
    public:
        virtual ~RealSubject();
        virtual void Request();
    };

    class Proxy : public Subject
    {
    public:
        Proxy();
        virtual ~Proxy();
        virtual void Request();
    private:
        RealSubject* realSubject;
    };

    void TestProxy();
}


#endif // PROXY_H
