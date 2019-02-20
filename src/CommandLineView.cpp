#include "CommandLineView.h"

/*
 * constructors and instance
 * managment
 * constructors are private
 */
CommandLineView::CommandLineView()
{}

CommandLineView::~CommandLineView()
{}

CommandLineView* CommandLineView::get_instance()
{
    if (!instance)
    {
        instance = new CommandLineView();
    }
    return instance;
}

void CommandLineView::release_instance()
{
    if (instance)
    {
        delete instance;
    }
    instance = NULL;
}

/*
 * Game displays
 */
void CommandLineView::display_game_begin()
{
    std::cout << "Welcome to Jaipur!" << std::endl << "Player 1, Enter your name: ";
    //wait for controller
    std::cout << "Is Player 1 a Human(1) or AI(2)?: ";
    //wait for controller
    //repeat for player 2
}

void CommandLineView::display_round_begin()
{}

void CommandLineView::display_pause()
{}

void CommandLineView::display_board()
{}

void CommandLineView::display_round_end()
{}

void CommandLineView::display_game_end()
{}

/*
 * Player displays
 */
void CommandLineView::display_player(Player& player)
{}

void CommandLineView::display_move_picker()
{}

void CommandLineView::display_move(Move& move)
{}

void CommandLineView::display_move_selections()
{}

/*
 * game object displays
 */
void CommandLineView::display_market(Market& market)
{}

void CommandLineView::display_hand(Hand& hand)
{}

void CommandLineView::display_bank(Bank& bank)
{}
