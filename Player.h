/*	The Player class is used to store all the data related to
	one of the game's players. (# of wins, cards in hand, etc.)
*/
#ifndef PLAYER_H
#define PLAYER_H


//#include "Game.h"
#include "Move.h"
#include "Card.h"
#include "Token.h"
#include "Hand.h"
#include "Bank.h"
#include <string>
#include <vector>
#include <stack>

class Player
{
    friend class Game;
    friend class Move;
protected:
	std::string name;				//the player's name
    Hand hand;						//all cards held by player; max 7
    std::vector<Token*> tokens;		//tokens currently owned by player
	int wins;						//number of seals of excellence player has
                                    //the player's herd
    int score;


public:
    Player();
    Player (std::string name);
    virtual ~Player();
	virtual Move* getMove(Market&, Bank&) = 0;  //the player gets an option to take a card, exchange
    void printStats();
	void clear();
    void addCard(Card* card);
    void addPoints(int points);
    Hand* getHand();
    int getScore();
};
#endif
