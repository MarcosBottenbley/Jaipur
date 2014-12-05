#include "Trade.h"

void Trade::makeMove()
{
	int *mrktIs = player.selectMarketCards();
	int *handIs = player.selectHandCards();
	int camels = player.selectCamels();
	int i = 0;
	int size = (sizeof(handIs)/sizeof(*handIs)) + camels;
	int size2 = (sizeof(mrktIs)/sizeof(*mrktIs));
	if(size != size2)
		throw exception;//TODO:make exception

	for(i; i < camels; i++)
	{
		if(hand.size() < 7)
			hand.add(market.remove(i));
		market.add(herd.pop());
	}
	if(handIs != 0)
	{
		for(int x = 0; x < size2; x++)
		{
			hand.add(market.remove(i));
			market.add(hand.remove(x));
			i++;
		}
	}
}
