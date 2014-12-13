#include "Sell.h"

#include <string>
#include <stack>
#include <iostream>

Sell::Sell(Market &m, Hand &h, Bank &b, bool *p):
 Move(m,h),pCards(p),bank(b)
{}

Sell::~Sell()
{}

int Sell::makeMove()
{
	InvalidMoveEx ime;
	//checks: if "precious metal" that there are at least 2 cards
	vector<int> indexes = getIndexes(pCards,7);
	int size = indexes.size();

	std::string initType = hand.cardAt(indexes[0])->getType();
	if(initType == "Gold" || initType == "Silver" || initType == "Diamond"){
		if(size < 2)
			throw ime;
	}

	//checks to see if all cards are of the same type
	std::string currType;
	for(int x = 1; x < size; x++){
		currType = hand.cardAt(indexes[x])->getType();
		if(currType != initType)
			throw ime;
	}

	//now that everything is checked it gets the tokens
	Type t(initType);
	std::stack<Token*> tokens = bank.getTokens(t.getEnum(),size);
	int points = 0;
	while(!tokens.empty()) {
		std::cout << tokens.top()->getValue() << std::endl;
		points += tokens.top()->getValue();
		delete tokens.top();
		tokens.pop();
	}
	
	for(int i = size-1; i >= 0; i--) {
		hand.removeCard(indexes[i]);
	}

	return points;
}
