#pragma once

#include "StateMachine.h"
#include "CommandLineView.h"
#include "CommandLineController.h"

class CommandLineStateMachine : public StateMachine
{
public:
    CommandLineStateMachine(State* startState);
    ~CommandLineStateMachine();
    void load_state();
    void run_state();
private:
    CommandLineView* view;
    CommandLineController* controller;
};
