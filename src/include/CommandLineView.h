#pragma once
#include <iostream>
#include <string>

#include "Player.h"
#include "Market.h"
#include "Bank.h"
#include "Hand.h"
#include "Move.h"

class CommandLineView
{
public:
    //error messages
    void display_int_input_error();
    void display_char_input_error();

    //game displays
    void display_game_begin();
    void display_name_input(int playerNum);
    void display_human_selection(int playerNum);
    void display_round_begin();
    void display_pause();
    void display_board();
    void display_round_end();
    void display_game_end();

    //player displays
    void display_player(Player& player);
    void display_move_picker();
    void display_move(Move& move);
    void display_move_selections();

    //game object displays
    void display_market(Market& market);
    void display_hand(Hand& hand);
    void display_bank(Bank& bank);
};
