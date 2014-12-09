#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include <vector>
#define MAX_SIZE 7

class Hand
{
	private:
		std::vector<Card *> hand;
	public:
		Hand();
		bool addCard(Card *);
		unsigned int handSize();
		bool removeCard(int);
		void printHand();
		bool isEmpty();
};
#endif
