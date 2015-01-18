#include "Memento.h"
#include <iostream>

namespace Memento
{

State::State()
    : _velocity(0)
    , _acceleration(0)
{
}

State::State(int velocity, int acceleration)
    : _velocity(velocity)
    , _acceleration(acceleration)
{
}

void State::Display()
{
    std::cout<<"state: velocity="<<_velocity<<", accelaration="<<_acceleration<<std::endl;
}

Memento::Memento(const State& state)
    : _state(state)
{
}

State Memento::GetState()
{
    return _state;
}

Memento* Originator::CreateMemento()
{
    return (new Memento(_state));
}

void Originator::SetState(const State& state)
{
    _state=state;
}

void Originator::SetMemento(Memento* memento)
{
    _state=memento->GetState();
}

void Originator::Display()
{
    _state.Display();
}

CareTaker::CareTaker()
    : _memento(NULL)
{
}

void CareTaker::SetMemento(Memento* memento)
{
    _memento=memento;
}

Memento* CareTaker::GetMemento()
{
    return _memento;
}

void TestMemento()
{
    std::cout<<"----------Test Memento----------"<<std::endl;
    Originator originator;
    CareTaker caretaker;

    //initialize
    originator.SetState(State(100, 100));
    originator.Display();

    //save state
    std::cout<<"save state..."<<std::endl;
    caretaker.SetMemento(originator.CreateMemento());

    //change state
    std::cout<<"change state..."<<std::endl;
    originator.SetState(State(99, 88));
    originator.Display();

    //restore state
    std::cout<<"restore state..."<<std::endl;
    originator.SetMemento(caretaker.GetMemento());
    originator.Display();
}

}
