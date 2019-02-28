#include "State.h"

bool State::stopped()
{
    return terminated;
}

State* State::get_next()
{
    return next;
}
