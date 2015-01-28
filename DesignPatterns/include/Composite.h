#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <string>
#include <list>
#include <algorithm>

namespace Composite
{

class Company
{
public:
    Company(std::string name);
    virtual ~Company();

    virtual void Add(Company* company)=0;
    virtual void Remove(Company* company)=0;
    virtual void Display(int depth)=0;
    virtual void Duty()=0;

protected:
    std::string _name;
};

class ConcreteCompany : public Company
{
public:
    ConcreteCompany(std::string name);
    virtual ~ConcreteCompany();

    virtual void Add(Company* company);
    virtual void Remove(Company* company);
    virtual void Display(int depth);
    virtual void Duty();

private:
    std::list<Company*> _children;
};

class HRDepartment : public Company
{
public:
    HRDepartment(std::string name);
    virtual ~HRDepartment();

    virtual void Add(Company* company);
    virtual void Remove(Company* company);
    virtual void Display(int depth);
    virtual void Duty();
};

void TestComposite();

}
#endif // COMPOSITE_H
