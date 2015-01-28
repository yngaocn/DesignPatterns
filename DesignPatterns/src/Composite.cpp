#include "Composite.h"
#include <iostream>

namespace Composite
{

Company::Company(std::string name)
    : _name(name)
{
}

Company::~Company()
{
}

ConcreteCompany::ConcreteCompany(std::string name)
    : Company(name)
{
}

ConcreteCompany::~ConcreteCompany()
{
}

void ConcreteCompany::Add(Company* company)
{
    _children.push_back(company);
}

void ConcreteCompany::Remove(Company* company)
{
    std::list<Company*>::iterator it=std::find(_children.begin(), _children.end(), company);
    if(it!=_children.end())
    {
        _children.erase(it, it);
    }
}

void ConcreteCompany::Display(int depth)
{
    std::cout<<std::string(depth, '-')+_name<<std::endl;
    std::list<Company*>::iterator it;
    for(it=_children.begin(); it!=_children.end(); ++it)
    {
        (*it)->Display(depth+2);
    }
}

void ConcreteCompany::Duty()
{
}

HRDepartment::HRDepartment(std::string name)
    : Company(name)
{
}

HRDepartment::~HRDepartment()
{
}

void HRDepartment::Add(Company* company)
{
    //leaf node, no add
}

void HRDepartment::Remove(Company* company)
{
    //leaf node, no remove
}

void HRDepartment::Display(int depth)
{
    std::cout<<std::string(depth+2, '-')+_name<<std::endl;
}

void HRDepartment::Duty()
{
    std::cout<<_name<<" Ô±¹¤ÕÐÆ¸"<<std::endl;
}

void TestComposite()
{
    std::cout<<"----------Test Composite----------"<<std::endl;
    Company* root=new ConcreteCompany("Root");
    Company* beijing_company=new ConcreteCompany("BeiJing");
    Company* beijing_hr_dept=new HRDepartment("BeiJing_HR");
    Company* shanghai_company=new ConcreteCompany("ShangHai");
    Company* shanghai_hr_dept=new HRDepartment("ShangHai_HR");

    beijing_company->Add(beijing_hr_dept);
    shanghai_company->Add(shanghai_hr_dept);

    root->Add(beijing_company);
    root->Add(shanghai_company);

    root->Display(0);

    delete beijing_hr_dept;
    delete shanghai_hr_dept;
    delete beijing_company;
    delete shanghai_company;
    delete root;
}

}
