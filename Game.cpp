#include "Game.h"		//includes Card.h, Token.h, Player.h vector and stack
#include "Market.h"
#include "Deck.h"
#include <iostream>
#include <cstdlib>		//for random numbers only
#include <ctime>

using std::vector;
using std::stack;		//TODO: necessary?
using std::string;
using std::cout;
using std::endl;

/* Constructor */
Game::Game() {
	std::srand(std::time(0));
}

Game::Game(int rndSeed) {
	std::srand(rndSeed);
}

/* Class Methods */
void Game::startGame() {
	player1 = new Human("Player1");		//for now, the names can be hard coded
	player2 = new Human("Player2");

}

void Game::startRound() {
	deck = new Deck();
	market = new Market(*deck);
	bank = new Bank();

	deck->deal(player1->hand, player2->hand);
}

void Game::printPlayers() {
    player1->printStats();
    cout << endl;
    player2->printStats();
}

void Game::printBoard() {
	cout << "Market:" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "[" << (market->getCard(i))->getType() << "] ";
	}
	cout << endl << endl;

	cout << "Bank:" << endl;
	bank->printBank();
}

bool Game::endRound() {		//returns true if a player reaches 2 wins, false otherwise
	//Determine Camel Winner
	if ((player1->hand).herdSize() > (player2->hand).herdSize())
		player1->score += 5;
	else if ((player2->hand).herdSize() > (player1->hand).herdSize())
		player2->score += 5;

	if (player1->score > player2->score)
		player1->wins++;
	else if (player2->score > player1->score)
		player2->wins++;
	else {		//if score tied...
		if (player1->tokens.size() > player2->tokens.size())
			player1->wins++;
		else if (player2->tokens.size() > player1->tokens.size())
			player2->wins++;
		else {
			//result in draw
		}
	}
	//need to fix this since camels are in hand now

	player1->clear();
	player2->clear();

	delete deck;
    delete market;
	delete bank;

	if (player1->wins == 2) {
		cout << player1->name << " wins!";
		return true;
	} else if (player2->wins == 2) {
		cout << player2->name << " wins!";
		return true;
	}
	return false;
}

void Game::endGame() {
	delete player1;
	delete player2;
}
