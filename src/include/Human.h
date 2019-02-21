/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#pragma once

#include "Move.h"
#include "Take.h"
#include "Trade.h"
#include "Sell.h"
#include "Player.h"
#include <string>


class Human : public Player
{
public:
    Human();
    Human(std::string name);
    virtual ~Human();

    Move* get_move(Market &market, Bank &bank);
    void sort_vector(std::vector<int>);
private:
    Take* take(Market &market);
    Trade* trade(Market &market);
    Sell* sell(Market &market, Bank &bank);

    void print_market_selections(Market& market, bool arr[]);
    void print_player_selections(bool arr[], int camels);
};
