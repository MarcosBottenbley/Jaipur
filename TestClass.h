/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

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
