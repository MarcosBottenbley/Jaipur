#include "Sell.h"

#include <string>
#include <stack>

Sell::Sell(Market &m, Hand &h, Bank &b, std::vector<Card*> p):
 Move(m,h), Bank(b), pCards(p)
{}

int Sell::makeMove()
{
	//checks: if "precious metal" that there are at least 2 cards
	int size = pCards.size();
	std::string initType = pCards[0]->getType();
	if(initType == "Gold" || initType == "Silver" || initType == "Diamond"){
		if(size < 2)
			throw InvalidMoveException;
	}
	//checks to see if all cards are of the same type
	std::string currType;
	for(int x = 1; x < size-1; x++){
		currType = pCards[x]->getType();
		if(currType != initType)
			throw InvalidMoveException;
	}

	//now that everything is checked it gets the tokens
	Type t(initType);
	Type::Enum e = t.getEnum();
	std::stack<Token*> tokens = b.getTokens(e,size);
	int points = 0;
	while(!tokens.empty()) {
		points += tokens.top()->getValue();
		delete tokens.top();
		tokens.pop();
	}

	return points;
}
