#include "Sell.h"

#include <string>

void Sell::makeMove()
{
	Card *handcards = player.selectHandCards();
	int size = (sizeof(handcards)/sizeof(*handcards));
	std::string initType = handcards[0]->getType();
	if(initType == "gold" || initType->getType() == "silver"){
		if(size < 2)
			throw exception;//TODO:make exeption
	} else {
		for(int x = 1; x < size-1; x++){
			if(handcards[x]->getType() != initType)
				throw exception;//TODO:make exception
		}
	}
	//may need a bank class
	player.addTokens(bank.getTokens(initType,size));
	if(size == 3)
		player.addTokens(bank.getBonusToken(3));//TODO:add or change
	else if(size == 4)
		player.addTokens(bank.getBonusToken(4));//TODO:add or change
	else if(size >= 5)
		player.addTokens(bank.getBonusToken(5));//TODO:add or change
}
