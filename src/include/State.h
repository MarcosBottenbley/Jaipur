#pragma once

#include "CommandLineView.h"
#include "CommandLineController.h"
class State
{
public:
    virtual ~State();
    virtual void init(CommandLineView*, CommandLineController*) = 0;
    virtual void start() = 0;
    virtual void update(float dt) = 0;
    virtual void draw() = 0;
    bool stopped();
    State* get_next();
private:
    virtual void stop() = 0;
protected:
    bool terminated;
    State* next;
};
