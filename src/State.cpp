#include "State.h"

State::~State()
{}

bool State::stopped()
{
    return terminated;
}

State* State::get_next()
{
    return next;
}
