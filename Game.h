/*  The Game class represents a game of Jaipur. This class contains
	both players and all the elements present on the game field.
*/

#ifndef GAME_H
#define GAME_H

#include <vector>
#include <stack>
#include <string>
#include "Player.h"
#include "Human.h"
#include "Bank.h"

class Market;

class Game
{
	friend class Move;
	friend class Market;
private:
	Player* player1;
	Player* player2;
	Market* market;				//the 5 cards that players can take or exchange
	Bank* bank;			//vector of 9 token arrays representing the
									//6 types of goods tokens and 3 types of bonus tokens
	std::stack<Card*> deck;				//the deck of cards

	void dealCards();				//shuffles deck, sets up market and deals cards
	void setupBank();				//sets up tokens in bank

	void tokenShuffle(std::vector<Token*> &bv, std::string item, int tempArr[], int numTokens);

public:
	Game();
	Game(int rndSeed);				//constructs game with a seed for the RNG
	void startGame();
	void startRound();				//resets the deck, market, and token piles, and
									//deals a hand of 5 cards to each player
	void fillMarket();				//deals cards from the deck to fill any empty
									//spaces in the market
	void printBoard();
	void printDeck();
	void printPlayers();

	Card* getCard(int index);
	//Card* takeCard(int index);					//take a card from the market (currently part of Market class)
	//Card* swapCard(int index, Card* card);		//swap cards with the market (currently part of Market class)
	std::vector<Card*> takeCamels();
	//std::vector<Token*> getTokens(std::string,int);       (currently part of Bank class)

	bool endRound();				//tallies player scores and awards a win to the
									//player with the most rupees.
	void endGame();					//deallocates all memory used by the current game
};

#endif
