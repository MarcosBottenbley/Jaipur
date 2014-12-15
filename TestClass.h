#ifndef TESTCLASS_H
#define TESTCLASS_H

#include "Take.h"
#include "Sell.h"
#include "Trade.h"

class TestClass 
{
	public:
		TestClass();
		~TestClass();
		void testBank();
		void testDeck();
		void testMarket();
		void testHand();
		void testTake();
		void testSell();
		void testTrade();
};
#endif
