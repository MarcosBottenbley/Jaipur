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

class Game
{
	friend class Move;
private:
	Player* player1;
	Player* player2;
	Market market[5];				//the 5 cards that players can take or exchange
	std::vector<Token*> bank[9];			//vector of 9 token arrays representing the
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
	//Card* takeCard(int index);					//take a card from the market
	//Card* swapCard(int index, Card* card);		//swap cards with the market
	std::vector<Card*> takeCamels();
	std::vector<Token*> getTokens(std::string,int);

	bool endRound();				//tallies player scores and awards a win to the
									//player with the most rupees.
	void endGame();					//deallocates all memory used by the current game
};

#endif
