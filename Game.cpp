#include "Game.h"		//includes Card.h, Token.h, Player.h vector and stack
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
	dealCards();
	setupBank();
}

//void Game::initPlayers() {
	//might be necessary later when we add AI players

//}

/**
 * Shuffles cards and deals them to players, puts cards in market, and
 * sets up the deck.
 */
void Game::dealCards() {
	Card* tempDeck[52];
	int i;
	
	/* Create cards */
	for (i = 0; i < 6; i++) {
		tempDeck[i] = new Card("Diamond");
		tempDeck[i+6] = new Card("Gold");
		tempDeck[i+12] = new Card("Silver");
	}
	for (i = 0; i < 8; i++) {
		tempDeck[i+18] = new Card("Cloth");
		tempDeck[i+26] = new Card("Spice");
		tempDeck[i+34] = new Card("Camel");
	}
	for (i = 42; i < 52; i++) {
		tempDeck[i] = new Card("Leather");
	}

	/* Shuffle & Deal */
	int cardsInDeck = 52;
	int currRand;
	for (i = 0; i < 40; i++) {
		currRand = std::rand() % cardsInDeck;			//pick random card from list
		deck.push(tempDeck[currRand]);					//push that card onto deck
		tempDeck[currRand] = tempDeck[cardsInDeck--];	//remove the card from the list
	}
	for (i = 0; i < 5; i++) {
		currRand = std::rand() % cardsInDeck;
		player1->addCard(tempDeck[currRand]);
		tempDeck[currRand] = tempDeck[cardsInDeck--];

		currRand = std::rand() % cardsInDeck;
		player2->addCard(tempDeck[currRand]);
		tempDeck[currRand] = tempDeck[cardsInDeck--];
	}

	//set other two cards as market cards. Add 3 camels to market.	
	market[0] = tempDeck[0];
	market[1] = tempDeck[1];
	for (i = 2; i < 5; i++) {
		market[i] = new Card("Camel");
	}
}

/**
 * Sets up all the tokens in the bank.
 */
void Game::setupBank() {
	//0 is diamond, 1 is gold, 2 silver, 3 cloth, 4 spice, 5 leather
	//	6 is 3card bonus, 7 is 4card bonus, 8 is 5card bonus
	//The back element is the top of the stack. Use back() to access
	//	and pop_back to remove
	int i;
	for (i = 0; i < 2; i++) {
        bank[0].push_back(new Token("Diamond", 5));
        bank[1].push_back(new Token("Gold", 5));
        bank[2].push_back(new Token("Silver", 5));
	}
	for (i = 0; i < 3; i++) {
		bank[0].push_back(new Token("Diamond", 7));
        bank[1].push_back(new Token("Gold", 6));
        bank[2].push_back(new Token("Silver", 5));
	}

	bank[3].push_back(new Token("Cloth", 1));
	bank[3].push_back(new Token("Cloth", 1));
	bank[3].push_back(new Token("Cloth", 2));
	bank[3].push_back(new Token("Cloth", 2));
	bank[3].push_back(new Token("Cloth", 3));
	bank[3].push_back(new Token("Cloth", 3));
	bank[3].push_back(new Token("Cloth", 5));

	bank[4].push_back(new Token("Spice", 1));
	bank[4].push_back(new Token("Spice", 1));
	bank[4].push_back(new Token("Spice", 2));
	bank[4].push_back(new Token("Spice", 2));
	bank[4].push_back(new Token("Spice", 3));
	bank[4].push_back(new Token("Spice", 3));
	bank[4].push_back(new Token("Spice", 5));

	for (i = 0; i < 6; i++) {
		bank[5].push_back(new Token("Leather", 1));
	}
	bank[5].push_back(new Token("Leather", 2));
	bank[5].push_back(new Token("Leather", 3));
	bank[5].push_back(new Token("Leather", 4));

	int tempArr[7] = {1, 1, 2, 2, 2, 3, 3};
	tokenShuffle(bank[6], "3 Bonus", tempArr, 7);			//TODO: might need to be &tempArr
	int tempArr2[6] = {4, 4, 5, 5, 6, 6};				//TODO: reassignment might not work
	tokenShuffle(bank[7], "4 Bonus", tempArr2, 6);
	int tempArr3[5] = {8, 8, 9, 10, 10};
	tokenShuffle(bank[8], "5 Bonus", tempArr3, 5);
}

/**
 * Shuffles the Tokens in tempArr and pushes them into bankVector. Same
 * shuffling algorithm as for the Cards in dealCards().
 * @param bv vector from bank used to store the tokens
 * @param item type of item being traded
 * @param tempArr array holding the values to be put in random order
 * @param numTokens number of values to be put into the vector
 */
void Game::tokenShuffle(vector<Token*> &bv, string item, int tempArr[], int numTokens) {
	int currRand;

	for (int i = numTokens; i > 0; i--) {
		currRand = rand() % i;
		bv.push_back(new Token(item, tempArr[currRand]));
		tempArr[currRand] = tempArr[i - 1];
	}
}

void Game::fillMarket() {

}

//TODO: remove for final game (?)
void printDeck() {
	stack<Card*> tempStack;
	for (int i = deck.size(); i > 0; i--) {
		cout << deck.top()->type << ", ";
		tempStack.push(deck.top);
		deck.pop();
	}
	for (int j = tempStack.size(); j > 0; j--) {
		deck.push(tempStack.top());
		tempStack.pop();
	}
	cout << endl;
}

Card* Game::getCard(int index) {
	return market[index];
}

Card* Game::takeCard(int index) {
	Card* tempCard = market[index];
	market[index] = deck.top();
	deck.pop();
	return tempCard;
}

Card* Game::swapCard(int index, Card* card) {
	Card* tempCard = market[index];
	market[index] = card;
	return tempCard;
}

vector<Card*> Game::takeCamels() {
	vector<Card*> camelVector;
	for (int i = 0; i < 5; i++) {
		if (market[i]->isCamel())
			camelVector.push_back(takeCard(i));
	}
	return camelVector;
}

vector<Token*> Game::getTokens(string type, int number) {
	vector<Token*> tokenList;
	int vectorNumber;
	if (type == "Diamond")
		vectorNumber = 0;
	else if (type == "Gold")
		vectorNumber = 1;
	else if (type == "Silver")
		vectorNumber = 2;
	else if (type == "Cloth")
		vectorNumber = 3;
	else if (type == "Spice")
		vectorNumber = 4;
	else if (type == "Leather")
		vectorNumber = 5;
	else {
		cout << "Invalid Token type\n";
		return 0;//0 means null
	}
	
	for (int i = 0; i < number; i++) {
		if (bank[vectorNumber].size() == 0)	//if no more tokens left...
			break;
		tokenList.push_back(bank[vectorNumber].back());
		bank[vectorNumber].pop_back();
	}
	
	if (number == 3) {			//bonus tokens
		tokenList.push_back(bank[6].back());
		bank[6].pop_back();
	} else if (number == 4) {
		tokenList.push_back(bank[7].back());
		bank[7].pop_back();
	} else if (number >= 5) {
		tokenList.push_back(bank[8].back());
		bank[8].pop_back();
	}

	return tokenList;
}

void Game::printBoard() {
	for (int i = 0; i < 5; i++) {
		cout << "[" << market[i]->type << "] ";
	}
	cout << endl;

}

bool Game::endRound() {		//returns true if a player reaches 2 wins, false otherwise
	//Determine Camel Winner
	if (player1->camels > player2->camels)
		player1->score += 5;
	else if (player2->camels > player1->camels)
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

	player1->clear();
	player2->clear();

	/* Clear Deck */
	for (int a = deck.size(); a > 0; a++) {
		delete deck.top();
		deck.pop(); 
	}

	/* Clear Bank */
	for (int i = 0; i < 9; i++) {
		for (int j = bank[i].size(); j > 0; j++) {
			delete bank[i].back();
			bank[i].pop_back();
		}
	}
	
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
	player1->clear();
	player2->clear();
	delete player1;
	delete player2;
}

