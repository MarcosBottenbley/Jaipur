#pragma once

#include "State.h"

class StateMachine
{
public:
    virtual ~StateMachine();
    virtual void load_state() = 0;
    virtual void run_state() = 0;
protected:
    State* currentState;
};
