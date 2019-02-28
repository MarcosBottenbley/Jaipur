#pragma once

#include "CommandLineView.h"
#include "CommandLineController.h"
class State
{
public:
    virtual void init(CommandLineView*, CommandLineController*) = 0;
    virtual void start() = 0;
    virtual void update(float dt) = 0;
    virtual void draw() = 0;
    bool stopped();
    State* get_next();
    virtual void stop() = 0;
private:
    bool terminated;
    State* next;
};
