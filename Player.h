/*	The Player class is used to store all the data related to
	one of the game's players. (# of wins, cards in hand, etc.)
*/
#ifndef PLAYER_H
#define PLAYER_H


//#include "Game.h"
#include "Move.h"
#include "Card.h"
#include "Token.h"
#include <string>
#include <vector>
#include <stack>

class Player
{
    friend class Game;
    friend class Move;
protected:
	std::string name;					//the player's name
    std::vector<Card*> hand;     //goods cards held by player; max 7
    std::stack<Card*> camelCards;
	int handSize;					//how many goods cards are currently in
									//the player's hand
    std::vector<Token*> tokens;			//tokens currently owned by player
	int wins;						//number of seals of excellence player has
    int camels;                 //how many camel cards are currently in
                                    //the player's herd
    int score;


public:
    Player();
    Player (std::string name);
    virtual ~Player();
	virtual Move* getMove() = 0;  //the player gets an option to take a card, exchange
    void printStats();
    void clear();
    void addCard(Card* card);
    void addToken(Token* token);
    int getScore();
};
#endif
