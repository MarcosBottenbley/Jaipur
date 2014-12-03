#include "Game.h"		//includes Card.h, Token.h, vector and stack
#include "Player.h"
#include <iostream>
#include <cstdlib>		//for random numbers only
#include <ctime>

using std::vector;
using std::stack;		//TODO: necessary?
using std::string;

/* Constructor */
void Game::Game() {
    std::srand(std::time(0));
}

void Game::Game(int rndSeed) {
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
		player1.addCard(tempDeck[currRand]);
		tempDeck[currRand] = tempDeck[cardsInDeck--];

        currRand = std::rand() % cardsInDeck;
        player2.addCard(tempDeck[currRand]);
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
		bank[0].push_back(new Token("Diamond", 5);
        bank[1].push_back(new Token("Gold", 5);
        bank[2].push_back(new Token("Silver", 5);
	}
	for (i = 0; i < 3; i++) {
		bank[0].push_back(new Token("Diamond", 7);
        bank[1].push_back(new Token("Gold", 6);
        bank[2].push_back(new Token("Silver", 5);
	}

	bank[3].push_back(new Token("Cloth", 1);
    bank[3].push_back(new Token("Cloth", 1);
    bank[3].push_back(new Token("Cloth", 2);
    bank[3].push_back(new Token("Cloth", 2);
    bank[3].push_back(new Token("Cloth", 3);
    bank[3].push_back(new Token("Cloth", 3);
    bank[3].push_back(new Token("Cloth", 5);

    bank[4].push_back(new Token("Spice", 1);
    bank[4].push_back(new Token("Spice", 1);
    bank[4].push_back(new Token("Spice", 2);
    bank[4].push_back(new Token("Spice", 2);
    bank[4].push_back(new Token("Spice", 3);
    bank[4].push_back(new Token("Spice", 3);
    bank[4].push_back(new Token("Spice", 5);

	for (i = 0; i < 6; i++) {
		bank[5].push_back(new Token("Leather", 1);
	}
    bank[5].push_back(new Token("Leather", 2);
    bank[5].push_back(new Token("Leather", 3);
    bank[5].push_back(new Token("Leather", 4);

	int tempArr[7] = {1, 1, 2, 2, 2, 3, 3}
	tokenShuffle(bank[6], tempArr, 7);			//TODO: might need to be &tempArr
	tempArr = {4, 4, 5, 5, 6, 6};				//TODO: reassignment might not work
	tokenShuffle(bank[7], tempArr, 6);
	tempArr = {8, 8, 9, 10, 10};
	tokenShuffle(bank[8], tempArr, 5);

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


void Game::printBoard() {



}

void Game::endRound() {


}

void Game::endGame() {


}


