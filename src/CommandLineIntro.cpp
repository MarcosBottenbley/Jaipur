#include "CommandLineIntro.h"

void CommandLineIntro::init(CommandLineView* view, CommandLineController* controller)
{
    this->view = view;
    this->controller = controller;
    //set next state here
    //this->next =
}

void CommandLineIntro::start()
{
    player1Name = "";
    player2Name = "";

    player1Type = 0;
    player2Type = 0;
    view->display_game_begin();
}

void CommandLineIntro::update(float dt)
{
    if (player1Name == "")
    {
        controller->get_commandline_input(player1Name);
        return;
    }
    else if (player2Name == "")
    {
        controller->get_commandline_input(player2Name);
        return;
    }

    if (player1Type == 0)
    {
        controller->get_commandline_input(player1Type);
        return;
    }
    else if (player2Type == 0)
    {
        controller->get_commandline_input(player2Type);
        return;
    }
    stop();
}

void CommandLineIntro::draw()
{
    if (player1Name == "")
    {
        view->display_name_input(1);
        return;
    }
    else if (player2Name == "")
    {
        view->display_name_input(2);
        return;
    }

    if (player1Type == 0)
    {
        view->display_human_selection(1);
        return;
    }
    else if (player2Type == 0)
    {
        view->display_human_selection(2);
        return;
    }
}

void CommandLineIntro::stop()
{
    Player* player1, *player2;
    if (player1Type == 1)
    {
        player1 = new Human(player1Name);
    }
    else
    {
        player1 = new AI(player1Name);
    }

    if (player2Type == 1)
    {
        player2 = new Human(player2Name);
    }
    else
    {
        player2 = new AI(player2Name);
    }
    //init next state with the initiated players
}
