#pragma once
#include "State.h"
#include "CommandLineView.h"
#include "CommandLineController.h"
#include "Player.h"
#include "Human.h"
#include "AI.h"
#include "Game.h"

class CommandLineIntro : public State
{
public:
    void init(CommandLineView*, CommandLineController*);
    void start();
    void update(float dt);
    void draw();
private:
    void stop();
private:
    std::string player1Name, player2Name;

    int player1Type, player2Type;

    CommandLineView* view;
    CommandLineController* controller;
};
