#include "Observer.h"
#include <iostream>

namespace Observer
{
    Observer::Observer(Subject* subject)
        : subject(subject)
    {
    }

    Observer::~Observer()
    {
    }

    DoorObserver::DoorObserver(Subject* subject)
        : Observer(subject)
    {
    }

    DoorObserver::~DoorObserver()
    {
    }

    void DoorObserver::Update()
    {
        if(subject!=NULL)
        {
            std::cout<<"Update door ["<<subject->GetName()<<"] state= "<<subject->GetState()<<std::endl;
        }
        else
        {
            std::cout<<"Update door state error, subject is null"<<std::endl;
        }
    }

    LightObserver::LightObserver(Subject* subject)
        : Observer(subject)
    {
    }

    LightObserver::~LightObserver()
    {
    }

    void LightObserver::Update()
    {
        if(subject!=NULL)
        {
            std::cout<<"Update light ["<<subject->GetName()<<"] state= "<<subject->GetState()<<std::endl;
        }
        else
        {
            std::cout<<"Update light state error, subject is null"<<std::endl;
        }
    }

    Subject::Subject(std::string name)
        : name(name)
        , state(0)
    {
    }

    std::string Subject::GetName()
    {
        return name;
    }

    Door::Door(std::string name)
        : Subject(name)
    {
    }

    void Door::AddObserver(Observer* observer)
    {
        observer_list.push_back(observer);
    }

    void Door::RemoveObserver(Observer* observer)
    {
        std::vector<Observer*>::iterator it;
        for(it=observer_list.begin(); it!=observer_list.end(); ++it)
        {
            if(*it==observer)
            {
                observer_list.erase(it);
            }
        }
    }

    void Door::Notify()
    {
        std::vector<Observer*>::iterator it;
        for(it=observer_list.begin(); it!=observer_list.end(); ++it)
        {
            (*it)->Update();
        }
    }

    void Door::ChangeState(int state)
    {
        this->state=state;
    }
    int Door::GetState()
    {
        return state;
    }

    Light::Light(std::string name)
        : Subject(name)
    {
    }

    void Light::AddObserver(Observer* observer)
    {
        observer_list.push_back(observer);
    }

    void Light::RemoveObserver(Observer* observer)
    {
        std::vector<Observer*>::iterator it;
        for(it=observer_list.begin(); it!=observer_list.end(); ++it)
        {
            if(*it==observer)
            {
                observer_list.erase(it);
            }
        }
    }

    void Light::Notify()
    {
        std::vector<Observer*>::iterator it;
        for(it=observer_list.begin(); it!=observer_list.end(); ++it)
        {
            (*it)->Update();
        }
    }

    int Light::GetState()
    {
        return state;
    }

    void Light::ChangeState(int state)
    {
        this->state=state;
    }

    void TestObserver()
    {
        std::cout<<"----------TestObserver----------"<<std::endl;

        Door door("Front door");
        Light light("Lamp light");

        Observer* doorObserver=new DoorObserver(&door);
        Observer* lightObserver=new LightObserver(&light);

        door.AddObserver(doorObserver);
        light.AddObserver(lightObserver);

        door.ChangeState(1);
        light.ChangeState(2);

        door.Notify();
        light.Notify();

        delete doorObserver;
        delete lightObserver;
    }
}
