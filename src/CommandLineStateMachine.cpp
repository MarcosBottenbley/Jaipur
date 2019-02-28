#include "CommandLineStateMachine.h"

CommandLineStateMachine::CommandLineStateMachine(State* startState)
{
    currentState = startState;
    view = new CommandLineView();
    controller = new CommandLineController();
}

CommandLineStateMachine::~CommandLineStateMachine()
{
    delete view;
    delete controller;
}

void CommandLineStateMachine::load_state()
{
    if (currentState)
    {
        currentState->init(view,controller);
        run_state();
    }
}

void CommandLineStateMachine::run_state()
{
    currentState->start();
    do
    {
        currentState->draw();
        currentState->update(0);
    }
    while(!currentState->stopped());
    //currentState = currentState->get_next();
    load_state();
}
