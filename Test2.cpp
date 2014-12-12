#include "Market.h"
#include "Hand.h"
#include "Card.h"
#include "Deck.h"
#include "Move.h"
#include "Take.h"
#include "Sell.h"
#include "Trade.h"
#include "Bank.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using std::cout;
using std::endl;

int main() {
	//std::srand(std::time(0));
	std::srand(80085);
	
	Deck* d = new Deck();
	Market* m = new Market(*d);
	Bank b;

	Hand h1;
	Hand h2;


	d->printDeck();
	m->printMarket();

	d->deal(h1,h2);

	cout << endl;
	cout << "Testing hand" << endl;
	cout << endl;

	h1.printHand();
	h2.printHand();

	cout << endl;
	cout << "Testing take" << endl;
	cout << endl;

	Take t(*m,h1,0);
	t.makeMove();

	h1.printHand();
	m->printMarket();

	cout << endl;
	cout << "move 2 " << endl;
	cout << endl;
	Take t2(*m,h1,1);
	t2.makeMove();

	h1.printHand();
	m->printMarket();

	cout << endl;
	cout << "Trade test" << endl;
	cout << endl;

	bool parr[7] = {false,true,false,false,false,false,false};
	bool marr[5] = {false,false,false,true,true};
	Trade td(*m,h2,parr,marr,1);
	td.makeMove();

	h2.printHand();
	m->printMarket();

	cout << endl;
	cout << "Sell test" << endl;
	cout << endl;

	int points;
	bool sarr[7] = {true,false,true,true,true,false,false};
	Sell s(*m,h2,b,sarr);
	points = s.makeMove();

	h2.printHand();
	cout << "Points earned: " << points << endl;
	m->printMarket();
}
