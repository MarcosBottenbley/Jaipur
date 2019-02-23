#pragma once
#include "State.h"

class MainMenu : public State
{
public:
    void init();
    void start();
    void update(float dt);
    void draw();
    void stop();
};
