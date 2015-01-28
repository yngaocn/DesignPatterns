#include <iostream>
#include "Proxy.h"
#include "SimpleFactory.h"
#include "FactoryMethod.h"
#include "Prototype.h"
#include "TemplateMethod.h"
#include "Facade.h"
#include "Builder.h"
#include "Observer.h"
#include "AbstractFactory.h"
#include "State.h"
#include "Adapter.h"
#include "Memento.h"
#include "Composite.h"



#include "Command.h"

using namespace std;

int main()
{
    //Test SimpleFactory
    SimpleFactory::TestSimpleFactory();

    //Test FactoryMethod
    FactoryMethod::TestFactoryMethod();

    //Test Proxy
    Proxy::TestProxy();

    //Test Prototype
    Prototype::TestPrototype();

    //Test TemplateMethod
    TemplateMethod::TestTemplateMethod();

    //Test Facade
    Facade::TestFacade();

    //Test Builder
    Builder::TestBuilder();

    //Test Observer
    Observer::TestObserver();

    //Test AbstractFactory
    AbstractFactory::TestAbstractFactory();

    //Test State
    State::TestState();

    //Test Adapter
    Adapter::TestAdapter();

    //Test Memento
    Memento::TestMemento();

    //Test Composite
    Composite::TestComposite();

    //Test Command
    Command::TestCommand();

    return 0;
}
