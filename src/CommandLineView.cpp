#include "CommandLineView.h"

/*
 * Error messages
 */
void CommandLineView::display_int_input_error()
{
    std::cout << "Please enter a valid number" << std::endl;
    std::cin.clear();
    std::cin.ignore(100, '\n');
}

void CommandLineView::display_char_input_error()
{
    std::cout << "Please enter a valid character" << std::endl;
    std::cin.clear();
    std::cin.ignore(100, '\n');
}

/*
 * Game displays
 */
void CommandLineView::display_game_begin()
{
    std::cout << "Welcome to Jaipur!" << std::endl;
}

void CommandLineView::display_name_input(int playerNum)
{
    std::cout << "Player " << playerNum << ", Enter your name: ";
}

void CommandLineView::display_human_selection(int playerNum)
{
    std::cout << "Is Player " << playerNum << " a Human(1) or AI(2)?: ";
}

void CommandLineView::display_round_begin()
{
    std::cout << "Starting new round!" << std::endl;
}

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
