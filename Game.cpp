#include "Game.h"		//includes Card.h, Token.h, vector and stack
#include "Player.h"
#include <iostream>
#include <cstdlib>		//for random numbers only
#include <ctime>

/* Constructor */
void Game::Game() {


}

/* Class Methods */
void Game::startGame() {
	player1 = new Human("Player1");		//for now, the names can be hard coded
	player2 = new Human("Player2");
}

void Game::startRound() {
	dealCards();
	setupBank();

	//setup players (ex. initialize token vectors)
}

//void Game::initPlayers() {
	//might be necessary later when we add AI players

//}

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
		std::srand(std::time(0));
		currRand = std::rand() % cardsInDeck;
		deck.push(tempDeck[currRand]);
		tempDeck[currRand] = tempDeck[cardsInDeck--];
	}
	for (i = 0; i < 5; i++) {
		//player1.addCard
		//player2.addCard
	}
	//set other two cards as market cards. Add 3 camels to market.
}

void Game::setupBank() {
	//0 is diamond, 1 is gold, 2 silver, 3 cloth, 4 spice, 5 leather
	//6 is 3card bonus, 7 is 4card bonus, 8 is 5card bonus
	for (int i = 0; i < 9; i++) {
		bank[i] = std::vector<Token*>
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


