#include "Command.h"
#include <iostream>

namespace Command
{
    void Receiver::Action()
    {
        std::cout<<"Receiver::Action()"<<std::endl;
    }

    Command::~Command()
    {
    }

    ConcreteCommand::ConcreteCommand(Receiver* receiver)
        : _receiver(receiver)
    {
    }

    ConcreteCommand::~ConcreteCommand()
    {
    }

    void ConcreteCommand::Execute()
    {
        if(NULL!=_receiver)
        {
            _receiver->Action();
        }
        else
        {
            std::cout<<"member _receiver is null."<<std::endl;
        }
    }

    Invoker::Invoker(Command* command)
        : _command(command)
    {
    }

    Invoker::~Invoker()
    {
    }

    void Invoker::Invoke()
    {
        if(NULL!=_command)
        {
            _command->Execute();
        }
        else
        {
            std::cout<<"member _command is null."<<std::endl;
        }
    }

    void TestCommand()
    {
        std::cout<<"----------Test Command----------"<<std::endl;
        Receiver receiver;
        Command* command=new ConcreteCommand(&receiver);
        Invoker invoker(command);
        invoker.Invoke();

        delete command;
    }
}

