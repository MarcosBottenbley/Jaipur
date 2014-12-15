#include "Game.h"		//includes Card.h, Token.h, Player.h vector and stack
#include "Market.h"
#include "Deck.h"
#include <iostream>
#include <cstdlib>		//for random numbers only
#include <ctime>
#include <climits>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cerr;
using std::cin;

/* Constructor */
Game::Game() {
	std::srand(std::time(0));
}

Game::Game(int rndSeed) {
	std::srand(rndSeed);
}

/* Class Methods */
void Game::startGame() {
	string str;
	cout << "Welcome to Jaipur!" << endl << "Player 1, Enter your name: ";
	cin >> str;
	player1 = new AI(str);

	cout << "Player 2, Enter your name: ";
	cin >> str;
	player2 = new AI(str);

	cin.ignore(256, '\n');
}

void Game::startRound() {
	deck = new Deck();
	market = new Market(*deck);
	bank = new Bank();

	deck->deal(player1->hand, player2->hand);
}

void Game::playGame() {
	Move* movePtr;
	int retVal;

	cout << "Starting new round!" << endl;

	while(1) {
		movePtr = player1->getMove(*market, *bank);
		retVal = executeMove(movePtr);
		player1->pause();
		if (retVal == -1)	//if invalid move, player1 tries again
			continue;
		else
			player1->addPoints(retVal);
		if (checkGameOver())
			break;
		while (1) {
			movePtr = player2->getMove(*market, *bank);
			retVal = executeMove(movePtr);
			player2->pause();
			if (retVal == -1)	//if invalid move, player2 tries again
				continue;
			else
				player2->addPoints(retVal);
			if (checkGameOver())
				return;
			break;
		}
	}
}

void Game::pause()
{
    char c;
    cin.ignore(INT_MAX, '\n');
    while(1)
    {
        std::cout << "Input Q to quit or C to continue: ";
        cin.get(c);
        if (tolower(c) == 'c')
            break;
	if (tolower(c) == 'q')
	{
	    cout << "Do you really want to quit? [Y/N]";
	    cin.get(c);
	    if (tolower(c) == 'y')
	    {
	        delete bank;
	        delete market;
	        delete deck;
		endGame();
	    }
	}
    }
}


// returns -1 on error, points earned if successful
int Game::executeMove(Move* mp) {
	int points;

	try {
		points = mp->makeMove();
	} catch (InvalidMoveEx e) {
		cerr << e.what() << endl;
		delete mp;
		return -1;
	}
	
	delete mp;
	return points;
}

bool Game::checkGameOver() {
        if (deck->gameOver() || bank->gameOver())
                return true;
        return false;
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

	if (player1->score > player2->score) {
		player1->wins++;
		cout << player1->name << " wins the round!" << endl << endl;
	}
	else if (player2->score > player1->score) {
		player2->wins++;
		cout << player2->name << " wins the round!" << endl << endl;
	}
	/*else {		//if score tied...
		if (player1->tokens.size() > player2->tokens.size())
			player1->wins++;
		else if (player2->tokens.size() > player1->tokens.size())
			player2->wins++;
		else {
			//result in draw
		}
	}*/

	player1->clear();
	player2->clear();

	delete deck;
	delete market;
	delete bank;

	if (player1->wins == 2) {
		cout << player1->name << " wins the game!" << endl;
		return true;
	} else if (player2->wins == 2) {
		cout << player2->name << " wins the game!" << endl;
		return true;
	}
	return false;
}

void Game::endGame() {
	delete player1;
	delete player2;
}
