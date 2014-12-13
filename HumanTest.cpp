#include "Human.h"
#include <cassert>
//#include <ctime>
#include <cstdlib>

int main() {
	std::srand(std::time(0));

	Human human("Calvin");
	human.printStats();
	std::cout << std::endl;	

	Human human2("Hobbes");

	Move* movePtr;

	Deck deck;
	Bank bank;
	deck.deal(*(human.getHand()), *(human2.getHand()));
	Market market(deck);

	movePtr = human.getMove(market, bank);
	movePtr->makeMove();
	human.printStats();
	market.printMarket();

	return 0;
}
