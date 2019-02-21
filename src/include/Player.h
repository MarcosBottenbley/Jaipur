/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

/*  The Player class is used to store all the data related to
    one of the game's players. (# of wins, cards in hand, etc.)
*/
#ifndef PLAYER_H
#define PLAYER_H


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

    int GetHandSize () const;
    int GetHerdSize () const;
    int GetNumWins () const;
    int getScore() const;
    const Hand* getHand() const;

    void clear();
    void addCard(Card* card);
    void addPoints(int points);

    friend std::ostream& operator<<(std::ostream& os, const Player& aPlayer);
};
#endif
