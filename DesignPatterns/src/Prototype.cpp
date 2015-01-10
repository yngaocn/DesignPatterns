#include "Prototype.h"

namespace Prototype
{
    Prototype1::Prototype1()
        : data(NULL)
    {
    }

    Prototype1::Prototype1(const char* data)
    {
        if(data==NULL)
        {
            this->data=new char[1];
            this->data[0]='\0';
        }
        else
        {
            this->data=new char[strlen(data)+1];
            strcpy(this->data, data);
        }
    }

    Prototype1::Prototype1(const Prototype1& prototype)
    {
        data=new char[strlen(prototype.data)+1];
        strcpy(data, prototype.data);
    }

    Prototype1::~Prototype1()
    {
        if(data!=NULL)
        {
            delete[] data;
            data=NULL;
        }
    }

    ICloneable* Prototype1::Clone()
    {
        return new Prototype1(*this);
    }

    void Prototype1::Disp()
    {
        std::cout<<"Prototype data: "<<this->data<<std::endl;
    }

    void TestPrototype()
    {
        std::cout<<"----------TestPrototype----------"<<std::endl;
        ICloneable* prototype1=new Prototype1("A");
        ICloneable* prototype2=new Prototype1("B");
        ICloneable* prototype3=prototype1->Clone();
        ICloneable* prototype4=prototype2->Clone();
        prototype1->Disp();
        prototype2->Disp();
        prototype3->Disp();
        prototype4->Disp();
    }
}

