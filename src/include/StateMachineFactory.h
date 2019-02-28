#pragma once

#include "StateMachine.h"
#include "CommandLineStateMachine.h"
#include "State.h"
#include "CommandLineIntro.h"

class StateMachineFactory
{
public:
    ~StateMachineFactory();
    StateMachine* create_statemachine(char type);
};
