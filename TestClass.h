#ifndef TESTCLASS_H
#define TESTCLASS_H

#include "Take.h"
#include "Sell.h"
#include "Trade.h"

class TestClass 
{
	private:
		Bank bank;
		Deck deck;
		Market market(d);
		Hand hand;
		Hand hand2;
	public:
		TestClass();
		~TestClass();
		void TestBank();
		void TestDeck();
		void TestMarket();
		void TestHand();
		void TestTake();
		void TestSell();
		void TestTrade();
}