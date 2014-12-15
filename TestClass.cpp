#include "TestClass.h"
#include <cassert>
#include <iostream>
#include <stack>

using std::stack;
using std::cout;
using std::endl;

TestClass::TestClass()
{}

TestClass::~TestClass()
{}

void TestClass::testBank()
{
	cout << "Testing bank" << endl;
	Bank bank;

	stack<Token*> s = bank.getTokens(Type::GOLD,2);
	assert(s.top()->getValue() == 6);

	stack<Token*> s2 = bank.getTokens(Type::SPICE,3);
	assert(s2.size() == 4);

	stack<Token*> s3 = bank.getTokens(Type::SILVER,2);
	assert(s3.top()->getValue() == 5);

	stack<Token*> s4 = bank.getTokens(Type::LEATHER,9);
	assert(s4.size() == 10);

	bank.getTokens(Type::DIAMOND, 5);
	bank.getTokens(Type::CLOTH, 7);

	assert(bank.gameOver() == true);

	cout << "Bank test completed successfully\n" << endl;
}

void TestClass::testDeck()
{
	cout << "Testing deck" << endl;
	Deck deck;
	Hand hand1;
	Hand hand2;

	cout << "Printing the deck" << endl;
	deck.printDeck();
	cout << "Dealing cards to the hands" << endl;
	deck.deal(hand1,hand2);
	assert(hand1.herdSize() == 1);
	assert(hand1.handSize() == 4);

	assert(hand2.herdSize() == 1);
	assert(hand2.handSize() == 4);

	assert(hand1.cardAt(0)->getType() == "Spice");
	assert(hand1.cardAt(1)->getType() == "Silver");
	assert(hand1.cardAt(2)->getType() == "Leather");
	assert(hand1.cardAt(3)->getType() == "Spice");

	assert(hand2.cardAt(0)->getType() == "Gold");
	assert(hand2.cardAt(1)->getType() == "Cloth");
	assert(hand2.cardAt(2)->getType() == "Diamond");
	assert(hand2.cardAt(3)->getType() == "Leather");

	assert(deck.getCard()->getType() == "Camel");
	
	for(int x = 0; x < 42; x++) {
		deck.getCard();
	}

	assert(deck.gameOver() == true);
	cout << "Deck testing completed successfully\n" << endl;
}

void TestClass::testMarket()
{
	cout << "Testing Market" << endl;
	Deck deck;
	cout << "Printing Deck" << endl;
	deck.printDeck();

	Market market(deck);

	assert(market.getCard(0)->getType() == "Camel");
	assert(market.getCard(1)->getType() == "Camel");
	assert(market.getCard(2)->getType() == "Camel");
	assert(market.getCard(3)->getType() == "Leather");
	assert(market.takeCard(4)->getType() == "Camel");

	assert(market.getCard(4)->getType() == "Cloth");
	assert(market.swapCard(3,new Card("Gold"))->getType() == "Leather");
	assert(market.getCard(3)->getType() == "Gold");

	cout << "Printing Market" << endl;
	market.printMarket();

	cout << "Market testing completed successfully\n" << endl;
}

void TestClass::testHand()
{
	Hand hand;

	assert(hand.isEmpty() == true);

	assert(hand.addCard(new Card("Gold")) == true);
	assert(hand.addCard(new Card("Gold")) == true);
	assert(hand.addCard(new Card("Gold")) == true);

	assert(hand.handSize() == 3);
	assert(hand.herdSize() == 0);

	assert(hand.isEmpty() == false);
	assert(hand.isHerdEmpty() == true);

	assert(hand.addCard(new Card("Gold")) == true);
	assert(hand.addCard(new Card("Gold")) == true);
	assert(hand.addCard(new Card("Gold")) == true);
	assert(hand.addCard(new Card("Diamond")) == true);
	assert(hand.addCard(new Card("Gold")) == false);

	for(int i = 0; i < 4; i++)
		assert(hand.addCard(new Card("Camel")) == true);

	assert(hand.herdSize() == 4);
	assert(hand.handSize() == 7);

	hand.printHand();

	assert(hand.isHerdEmpty() == false);

	assert(hand.removeCard(6)->getType() == "Diamond");
	
	for(int y = 5; y >= 0; y--)
		assert(hand.removeCard(y)->getType() == "Gold");

	assert(hand.isEmpty() == true);
	assert(hand.isHerdEmpty() == false);

	for(int x = 0; x < 4; x++)
		assert(hand.getCamel()->getType() == "Camel");
	assert(hand.isHerdEmpty() == true);

	cout << "Hand test completed successfully\n" << endl;
}

void TestClass::testTake()
{
	cout << "Testing Take move" << endl;
	Deck deck;
	Market market(deck);
	Hand hand1;
	Hand hand2;
	deck.deal(hand1,hand2);

	market.printMarket();
	hand1.printHand();

	Take t1(market,hand1,1);
	t1.makeMove();

	assert(hand1.herdSize() == 3);

	Take t2(market,hand1,4);
	t2.makeMove();

	assert(hand1.handSize() == 6);
	assert(hand1.herdSize() == 3);

	Take t3(market,hand1,3);
	t3.makeMove();

	assert(hand1.handSize() == 7);

	market.printMarket();

	Take t4(market,hand1,1);
	try {
		t4.makeMove();
	} catch (InvalidMoveEx e) {
		std::cerr << e.what() << endl;
	}

	Take t5(market,hand1,5);
	try {
		t5.makeMove();
	} catch (InvalidMoveEx e) {
		std::cerr << e.what() << endl;
	}

	cout << "Take test completed successfully\n" << endl;
}

void TestClass::testSell()
{	
	cout << "Testing Sell move" << endl;
	Deck deck;
	Market market(deck);
	Hand hand1;
	Hand hand2;
	Bank bank;
	deck.deal(hand1,hand2);

	hand1.printHand();
	hand2.printHand();
	
	bool arr0[7] = {true,false,true,false,false,false,false};
	bool arr1[7] = {true,true,false,false,true,false,false};
	bool arr2[7] = {true,false,false,false,false,false,false};
	bool arr3[7] = {true,true,false,false,false,false,false};

	Sell s1(market,hand1,bank,arr0);
	assert(s1.makeMove() > 0);

	Sell s2(market,hand2,bank,arr1);
	assert(s2.makeMove() > 0);

	Sell s3(market,hand1,bank,arr2);
	try {
		s3.makeMove();
	} catch (InvalidMoveEx e) {
		std::cerr << e.what() << endl;
	}

	Sell s4(market,hand2,bank,arr3);
	try {
		s4.makeMove();
	} catch (InvalidMoveEx e) {
		std::cerr << e.what() << endl;
	}

	cout << "Sell test completed successfully\n" << endl;
}

void TestClass::testTrade()
{
	cout << "Testing trade move" << endl;

	Deck deck;
	Market market(deck);
	Hand hand1;
	Hand hand2;
	deck.deal(hand1,hand2);
	Take t(market,hand1,0);
	t.makeMove();

	market.printMarket();
	hand1.printHand();

	bool marr0[5] = {true,true,false,false,false};
	bool marr1[5] = {false,false,false,true,true};
	bool marr2[5] = {true,false,false,true,false};
	bool marr3[5] = {false,true,true,true,false};
	bool marr4[5] = {false,true,false,false,false};
	bool marr5[5] = {false,true,true,false,false};


	bool parr0[7] = {true,true,false,false,false,false,false};
	bool parr1[7] = {true,false,false,false,false,false,false};
	bool parr2[7] = {false,false,false,false,false,false,false};
	bool parr3[7] = {true,true,false,false,false,false,false};
	bool parr4[7] = {true,false,false,false,false,false,false};
	bool parr5[7] = {false,false,false,false,false,false,false};


	Trade t1(market,hand1,parr0,marr0,0);
	t1.makeMove();

	assert(market.getCard(0)->getType() == "Diamond");
	assert(market.getCard(1)->getType() == "Cloth");

	assert(hand1.cardAt(3)->getType() == "Gold");
	assert(hand1.cardAt(4)->getType() == "Leather");

	cout << "\nTrade 1 made" << endl;
	market.printMarket();
	hand1.printHand();

	Trade t2(market,hand1,parr1,marr1,1);
	t2.makeMove();

	cout << "\nTrade 2 made" << endl;
	market.printMarket();
	hand1.printHand();

	assert(market.getCard(3)->getType() == "Camel");
	assert(market.getCard(4)->getType() == "Diamond");

	assert(hand1.cardAt(3)->getType() == "Leather");
	assert(hand1.cardAt(4)->getType() == "Spice");

	Take h2(market,hand2,3);
	h2.makeMove();

	Trade t3(market,hand2,parr2,marr2,2);
	t3.makeMove();

	cout << "\nTrade 3 made" << endl;
	market.printMarket();
	hand2.printHand();

	assert(market.getCard(0)->getType() == "Camel");
	assert(market.getCard(3)->getType() == "Camel");

	assert(hand2.cardAt(4)->getType() == "Diamond");
	assert(hand2.cardAt(5)->getType() == "Diamond");

	cout << "\nError Testing" << endl;
	market.printMarket();
	hand1.printHand();
	cout << endl;

	Trade t4(market,hand1,parr3,marr3,0);
	Trade t5(market,hand1,parr4,marr4,0);
	Trade t6(market,hand1,parr5,marr5,2);

	try {
		t4.makeMove();
	} catch (InvalidMoveEx e) {
		cout << e.what() << endl;
	}

	try {
		t5.makeMove();
	} catch (InvalidMoveEx e) {
		cout << e.what() << endl;
	}

	try {
		t6.makeMove();
	} catch (InvalidMoveEx e) {
		cout << e.what() << endl;
	}

	market.printMarket();
	hand1.printHand();

	cout << "Trade test completed successfully\n" << endl;
}
