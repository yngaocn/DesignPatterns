#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>
#include <string>

namespace Observer
{
    class Subject;

    class Observer
    {
    public:
        Observer(Subject* subject);
        virtual ~Observer();
        virtual void Update()=0;
    protected:
        Subject* subject;
    };

    class DoorObserver : public Observer
    {
    public:
        DoorObserver(Subject* subject);
        virtual ~DoorObserver();
        virtual void Update();
    };

    class LightObserver : public Observer
    {
    public:
        LightObserver(Subject* subject);
        virtual ~LightObserver();
        virtual void Update();
    };

    class Subject
    {
    public:
        Subject(std::string name);
        virtual void AddObserver(Observer* observer)=0;
        virtual void RemoveObserver(Observer* observer)=0;
        virtual void Notify()=0;
        virtual int GetState()=0;
        virtual void ChangeState(int state)=0;
        virtual std::string GetName();

    protected:
        std::vector<Observer*> observer_list;
        std::string name;
        int state;
    };

    class Door : public Subject
    {
    public:
        Door(std::string name);
        virtual void AddObserver(Observer* observer);
        virtual void RemoveObserver(Observer* observer);
        virtual void Notify();
        virtual int GetState();
        virtual void ChangeState(int state);
    };

    class Light : public Subject
    {
    public:
        Light(std::string name);
        virtual void AddObserver(Observer* observer);
        virtual void RemoveObserver(Observer* observer);
        virtual void Notify();
        virtual int GetState();
        virtual void ChangeState(int state);
    };

    void TestObserver();
}


#endif // OBSERVER_H
