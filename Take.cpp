#include "Take.h"

void Take::makeMove(vector<int> mcard,vector<int> ignore, int cignore)
{
	//make player a friend class
	//or make a hand class
	//Card *mrktcard = player.selectMarketCard(); //going to use later
	if(game.market[mcard.front()]->isCamel())
		takeCamels();
	else if(player.hand.size() < 7)
	{
		player.hand.push_back(game->takeCard(mcard.front()));
	}
	else
		throw InvalidMoveException;
}

void Take::takeCamels()
{
	//make player a friend class
	vector<Card*> mcamels = game.takeCamels();
	for(int x = 0; x < mcamels.size(); x++)
		player.camelCards.push(game->takeCard(mcard.front()));
}
