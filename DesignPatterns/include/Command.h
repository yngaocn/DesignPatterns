#ifndef COMMAND_H
#define COMMAND_H

namespace Command
{
    class Receiver
    {
    public:
        void Action();
    };

    class Command
    {
    public:
        virtual ~Command();
        virtual void Execute()=0;
    };

    class ConcreteCommand : public Command
    {
    public:
        ConcreteCommand(Receiver* receiver);
        virtual ~ConcreteCommand();
        virtual void Execute();

    private:
        Receiver* _receiver;
    };

    class Invoker
    {
    public:
        Invoker(Command* command);
        virtual ~Invoker();
        void Invoke();
    private:
        Command* _command;
    };

    void TestCommand();
}

#endif // COMMAND_H
