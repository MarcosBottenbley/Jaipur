#include "Trade.h"

void Trade::makeMove(vector<int> &mcards,vector<int> &pcards, int camels)
{
	int size = mcards.size();
	int size2 = pcards.size() + camels;

	if(size != size2)
		throw InvalidMoveException;

	if (camels + pcards > 7)
		throw InvalidMoveException;

	for(int i = 0; i < camels; i++)
	{
		player->addCard(game->swapCard(mcards[i], player->camelCards.top()));
		player->camelCards.pop();
	}
	for (int j = 0; j < pcards.size(); j++) {
		player->hand[pcards[j]] = game->swapCard(mcards[j+camels], player->hand[mcards[j]]);
	}
}
