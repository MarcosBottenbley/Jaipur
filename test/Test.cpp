/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

// Tests the Token, Card, Hand, and Bank classes.

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
    h.add_card(c1);
    h.add_card(new Card("Gold"));
    h.add_card(new Card("Gold"));
    h.add_card(new Card("Diamond"));
    h.add_card(new Card("Leather"));
    h.add_card(new Card("Gold"));
    h.add_card(new Card("Silk"));
    h.add_card(new Card("Silver"));
    h.add_card(new Card("Silver"));
    h.add_card(new Card("Camel"));
    h.add_card(new Card("Camel"));
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

    stack<Token*> test = b.get_tokens(Type::GOLD,3);
    while(!test.empty()) {
        cout << test.top()->getType() << " ";
        cout << test.top()->getValue() << endl;
        delete test.top();
        test.pop();
    }
}
