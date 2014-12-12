#include <cstdlib>
#include <iostream> //just for printDeck
#include "Deck.h"
#include "Market.h"
#include "Game.h"

using std::cout; // for printDeck method
using std::endl; //

Deck::Deck(Game * g)
{
    parent = g;
    initDeck();
}

void Deck::initDeck()
{
    Card* tempDeck[52];
	int i;

	/* Create cards */
	for (i = 0; i < 6; i++)
    {
		tempDeck[i] = new Card("Diamond");
		tempDeck[i+6] = new Card("Gold");
		tempDeck[i+12] = new Card("Silver");
	}
	for (i = 0; i < 8; i++)
    {
		tempDeck[i+18] = new Card("Cloth");
		tempDeck[i+26] = new Card("Spice");
		tempDeck[i+34] = new Card("Camel");
	}
	for (i = 42; i < 52; i++)
    {
		tempDeck[i] = new Card("Leather");
	}

	/* Shuffle cards */
    int cardsInDeck = 52;
	int currRand;

	for(i = 0; i < 52; i++)
    {
        currRand = std::rand() % cardsInDeck;			//pick random card from list
		cards.push(tempDeck[currRand]);					//push that card onto deck
		tempDeck[currRand] = tempDeck[--cardsInDeck];	//remove the card from the list
    }
}

void Deck::deal()
{
    int i;
    for (i = 0; i < 5; i++)
    {
        (parent->player1)->addCard(getCard());
        (parent->player2)->addCard(getCard());
    }

    (parent->market)->addCard(0, getCard());
    (parent->market)->addCard(1, getCard());
}

Card* Deck::getCard()
{
    Card * temp = cards.top();
    cards.pop();
    return temp;
}

//temporary method for testing
void Deck::printDeck() {
	std::stack<Card*> tempStack;
	for (int i = cards.size(); i > 0; i--) {
		cout << (cards.top())->getType() << ", ";
		tempStack.push(cards.top());
		cards.pop();
	}
	for (int j = tempStack.size(); j > 0; j--) {
		cards.push(tempStack.top());
		tempStack.pop();
	}
	cout << endl << endl;
}
