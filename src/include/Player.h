/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

/*  The Player class is used to store all the data related to
    one of the game's players. (# of wins, cards in hand, etc.)
*/
#pragma once


#include "Move.h"
#include "Card.h"
#include "Token.h"
#include "Hand.h"
#include "Bank.h"
#include <string>
#include <vector>
#include <stack>
#include <iostream>

class Player
{
    friend class Game;
    friend class Move;
protected:
    //the player's name
    std::string name;

    //all cards held by player; max 7
    Hand hand;

    //tokens currently owned by player
    std::vector<Token*> tokens;

    //number of seals of excellence player has
    int wins;

    //the player's herd
    int score;

public:
    Player();
    Player (std::string name);
    virtual ~Player();

    //the player gets an option to take a card, exchange
    virtual Move* get_move(Market&, Bank&) = 0;

    int get_hand_size () const;
    int get_herd_size () const;
    int get_num_wins () const;
    int get_score() const;
    const Hand* get_hand() const;

    void clear();
    void add_card(Card* card);
    void add_points(int points);

    friend std::ostream& operator<<(std::ostream& os, const Player& aPlayer);
};
