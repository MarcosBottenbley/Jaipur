#include "AI.h"
#include <string>

Move* AI::getMove(Market& market, Bank& bank)
{	
	//if hand is not full, take the first card in the market
	//(if the card is a camel, makeMove will take all camels)
	if(hand.handSize() != 7)
		return new Take(market, hand, 1);
	else
	{
		int i;
		std::string type1, type2;
		bool playerCards[7] {0};
		
		//if hand is full, go through the hand and sell the first card
		//you find that isn't a valuable card (gold, silver, diamond)
		for (i = 0; i < hand.handSize(); i++)
		{
			type1 = hand.cardAt(i)->getType();
			if (type1 != "Diamond" && type1 != "Gold" && type1 != "Silver")
			{
				playerCards[i - 1] = !(playerCards[i - 1])
				return new Sell(market, hand, bank, playerCards);
			}
		}
		
		//this code will only execute if the AI has a full hand of only valuables,
		//loops through every combination of two cards until it finds a valid one
		//and sells them
		for (i = 0; i < hand.handSize(); i++)
		{
			for (int j = 0; j < hand.handSize(); j++)
			{
				if (i == j)
					continue;
					
				type1 = hand.cardAt(i)->getType();
				type2 = hand.cardAt(j)->getType();
				
				if(type1 == type2)
				{
					playerCards[i - 1] = !(playerCards[i - 1]);
					playerCards[j - 1] = !(playerCards[j - 1]);
					return new Sell(market, hand, bank, playerCards);
				}
			}
		}
	}
}