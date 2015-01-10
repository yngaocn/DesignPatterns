#include "Proxy.h"

namespace Proxy
{
    Subject::~Subject()
    {
    }

    RealSubject::~RealSubject()
    {
    }

    void RealSubject::Request()
    {
        std::cout<<"RealSubject::Request"<<std::endl;
    }

    Proxy::Proxy()
        : realSubject(NULL)
    {
        if(realSubject==NULL)
        {
            realSubject=new RealSubject;
        }
    }
    Proxy::~Proxy()
    {
        if(realSubject!=NULL)
        {
            delete realSubject;
            realSubject=NULL;
        }
    }

    void Proxy::Request()
    {
        if(realSubject==NULL)
        {
            realSubject=new RealSubject;
        }
        realSubject->Request();
    }

    void TestProxy()
    {
        std::cout<<"----------Test Proxy----------"<<std::endl;
        Proxy proxy;
        proxy.Request();
    }
}
