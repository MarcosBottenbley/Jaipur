#include "Take.h"

void Move::makeMove()
{
	//make player a friend class
	//or make a hand class
	Card *mrktcard = player.selectMarketCard();
	if(mrktcard->getType() == "camel")
		takeCamels();
	else if(player.handsize() < 7)
	{
		Card *hand = player.getHand();
		for(int x = 0; x < 7; x++)
		{
			if(hand[x] == null)
				hand[x] = mrktcard;
		}
	}
}

void Move::takeCamels()
{
	//make player a friend class
	Card *herd = player.getHerd();
	int herdindex = player.herdSize()-1;
	for(int x = 0; x < 5; x++)
	{
		if(market[x]->getType() == "camel")
		{
			herd[herdindex] = market[x];
			market[x] = game.TopCard(); //change later
			//market[x] = null;
		}
	}
}

