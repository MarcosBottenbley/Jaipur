/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#include "Human.h"
#include <cassert>
//#include <ctime>
#include <cstdlib>

int main() {
    std::srand (std::time(0));

    Human human ("Calvin");
    std::cout << human << std::endl;
    std::cout << std::endl; 

    Human human2 ("Hobbes");

    Move* movePtr;

    Deck deck;
    Bank bank;
    deck.deal (*(human.getHand()), *(human2.getHand()));
    Market market(deck);

    movePtr = human.get_move(market, bank);
    movePtr->makeMove();
    std::cout << human << std::endl;
    market.printMarket();

    return 0;
}
