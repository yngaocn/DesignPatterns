#ifndef MEMENTO_H
#define MEMENTO_H

namespace Memento
{

class State
{
public:
    State();
    State(int velocity, int acceleration);
    void Display();

private:
    int _velocity;
    int _acceleration;
};

class Memento
{
public:
    Memento(const State& state);
    State GetState();

private:
    State _state;
};

class Originator
{
public:
    Memento* CreateMemento();
    void SetState(const State& state);
    void SetMemento(Memento* memento);
    void Display();

private:
    State _state;
};

class CareTaker
{
public:
    CareTaker();
    void SetMemento(Memento* memento);
    Memento* GetMemento();

private:
    Memento* _memento;
};

void TestMemento();

}
#endif // MEMENTO_H
