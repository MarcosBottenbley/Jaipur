#pragma once

class State
{
public:
    virtual void init() = 0;
    virtual void start() = 0;
    virtual void update(float dt) = 0;
    virtual void draw() = 0;
    virtual void stop() = 0;
};
