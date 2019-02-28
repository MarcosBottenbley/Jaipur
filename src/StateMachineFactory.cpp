#include "StateMachineFactory.h"
#include "CommandLineIntro.h"

StateMachineFactory::~StateMachineFactory()
{}

StateMachine* StateMachineFactory::create_statemachine(char type)
{
    switch (type)
    {
        case 'c':
            CommandLineIntro* cliBeginState = new CommandLineIntro();
            StateMachine* cliStateMachine = new CommandLineStateMachine(cliBeginState);
            return cliStateMachine;
    }
    return nullptr;
}
