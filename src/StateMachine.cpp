#include "StateMachine.h"

StateMachine::~StateMachine()
{
    delete currentState;
}
