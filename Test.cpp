#include "Token.h"
#include "Card.h"
#include "Hand.h"
#include "Bank.h"
#include "Type.h"

#include <iostream>
#include <cassert>
#include <stack>

using std::stack;
using std::cout;
using std::cin;
using std::endl;

int main()
{
	Token* t1 = new Token("Diamond",5);
	cout << t1->getType() << endl;
	cout << t1->getValue() << endl;

	Card* c1 = new Card("Silk");
	cout << c1->getType() << endl;
	assert(c1->isCamel() == false);

	cout << endl;
	cout << "Hand Test:" << endl;

	Hand h;
	h.addCard(c1);
	h.addCard(new Card("Gold"));
	h.addCard(new Card("Gold"));
	h.addCard(new Card("Diamond"));
	h.addCard(new Card("Leather"));
	h.addCard(new Card("Gold"));
	h.addCard(new Card("Silk"));
	h.addCard(new Card("Silver"));
	h.addCard(new Card("Silver"));
	h.addCard(new Card("Camel"));
	h.addCard(new Card("Camel"));
	h.printHand();

	cout << endl;
	Card *temp = h.removeCard(4);
	Card *htemp = h.getCamel();
	cout << "Removed " << temp->getType() << endl;
	cout << "Removed " << htemp->getType() << endl;
	cout << "printing hand" << endl;

	h.printHand();

	delete t1;
	delete temp;
	delete htemp;

	cout << endl;
	cout << "Bank Test:" << endl;
	Bank b;

	stack<Token*> test = b.getTokens(Type::GOLD,3);
	while(!test.empty()) {
		cout << test.top()->getType() << " ";
		cout << test.top()->getValue() << endl;
		delete test.top();
		test.pop();
	}
}
