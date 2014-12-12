#include "Trade.h"

Trade::Trade(Market &m, Hand &h, bool pc[], bool mc[]):
 Move(m,h), pCards(pc), mCards(mc)
{}

Trade::~Trade()
{}

int Trade::makeMove()
{
	int size = numElements(pCards, (int)hand.handSize());
	int size2 = numElements(mCards, 5);
	Card* temp = 0;

	if(size != size2)
		throw InvalidMoveException;
	else if(size > 5)
		throw InvalidMoveException;

	int pIndex = (int)hand.handSize()
	int mIndex = 5;

	for(int x = 0; x < size; x++) {
		pIndex = nextTrue(pCards, pIndex-1);	//get market index to swap
		mIndex = nextTrue(mCards, mIndex-1);	//get hand index to swap
		temp = hand.removeCard(pIndex);		//remove backmost hand card
		temp = market.swapCard(mIndex, temp);	//put in market and take out market card
		hand.addCard(temp);			//add market card to player's hand
	}

	return 0;
}

//Finds the backmost true entry in arr, starting at startIndex.
int nextTrue(bool arr[], int startIndex) {
	int i = startIndex;
	while(! arr[i]) {
		i--;
	}
	return i;
}

