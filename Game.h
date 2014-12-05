/*  The Game class represents a game of Jaipur. This class contains
	both players and all the elements present on the game field.
*/

#ifndef GAME_H
#define GAME_H

#include <vector>
#include <stack>
#include <string>
#include "Card.h"
#include "Token.h"
#include "Player.h"

class Game
{
private:
	Player* player1;
	Player* player2;
	Card*[5] market;				//the 5 cards that players can take or exchange
	std::vector<Token*>[9] bank;			//vector of 9 token arrays representing the
									//6 types of goods tokens and 3 types of bonus tokens
	std::stack<Card*> deck;				//the deck of cards

	void dealCards();				//shuffles deck, sets up market and deals cards
	void setupBank();				//sets up tokens in bank

	void Game::tokenShuffle(std::vector<Token*> &bv, std::string item, int tempArr[], int numTokens);

public:
	Game();
	Game(int rndSeed);				//constructs game with a seed for the RNG
	void startGame();				
	void startRound();				//resets the deck, market, and token piles, and
									//deals a hand of 5 cards to each player
	void fillMarket();				//deals cards from the deck to fill any empty
									//spaces in the market
	
	Card* takeCard(int index);					//take a card from the market
	Card* swapCard(int index, Card* card);		//swap cards with the market

	void endRound();				//tallies player scores and awards a win to the
									//player with the most rupees. If one player has
									//two wins, endGame() is called.
	void endGame();					//deallocates all memory used by the current game
}

#endif
