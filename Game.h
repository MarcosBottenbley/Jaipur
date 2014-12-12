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
#include "Market.h"
#include "Deck.h"

class Game
{
	friend class Move;

private:
	Player* player1;
	Player* player2;
	Market* market;				//the 5 cards that players can take or exchange
	Bank* bank;			//vector of 9 token arrays representing the
									//6 types of goods tokens and 3 types of bonus tokens
	Deck* deck;				//the deck of cards

	bool executeMove(Move*);
	bool checkGameOver();
public:
	Game();
	Game(int rndSeed);				//constructs game with a seed for the RNG
	void startGame();
	void startRound();				//resets the deck, market, and token piles, and
									//deals a hand of 5 cards to each player
	void playGame();
	void printBoard();
	void printPlayers();

	bool endRound();				//tallies player scores and awards a win to the
									//player with the most rupees.
	void endGame();					//deallocates all memory used by the current game
};

#endif
