#include "TestClass.h"

TestClass::TestClass()
{
	deck.deal(hand1,hand2);
}

TestClass::~TestClass()
{}

void TestClass::TestBank()
{
	bank.
}

void TestClass::TestDeck()
{
	
}

void TestCLass::TestMarket()
{
	
}

void TestClass::TestHand()
{
	
}

void TestClass::TestTake()
{
	Take t1(market,hand1,1);
	t1.makeMove();
	assert(hand.handSize() == 3);
	assert(hand.herdSize() == 3);
	
	Take t2(market,hand1,1);
	Take t2(market,hand1,1);
	Take t2(market,hand1,1);
	Take t2(market,hand1,1);
}

void TestClass::TestSell()
{
	
	bool arr0[7] = {false,false,false,false,false,false,false};
	bool arr1[7] = {false,false,false,false,false,false,false};
	bool arr2[7] = {false,false,false,false,false,false,false};
	bool arr3[7] = {false,false,false,false,false,false,false};
	
	Sell s1(market,hand1,arr0);
	Sell s2(market,hand2,arr)
}

void TestClass::TestTrade()
{
	bool marr0[5] = {false,false,false,false,false};
	bool marr1[5] = {false,false,false,false,false};
	bool marr2[5] = {false,false,false,false,false};
	bool marr3[5] = {false,false,false,false,false};

	bool parr0[7] = {false,false,false,false,false,false,false};
	bool parr1[7] = {false,false,false,false,false,false,false};
	bool parr2[7] = {false,false,false,false,false,false,false};
	bool parr3[7] = {false,false,false,false,false,false,false};
	
	Trade t1(market,hand2,marr0,parr0);
}