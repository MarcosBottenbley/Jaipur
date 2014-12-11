#include <iostream>
#include "Human.h"

using std::cout;
using std::cin;
using std::endl;

Human::Human() {
	wins = 0;
	camels = 0;
}

Human::Human(std::string hname) {		//TODO: is this stuff necessary? it's in Player.cpp already
    name = hname;
    score = 0;
    wins = 0;
    camels = 0;
}

Human::~Human()
{}

Move* Human::getMove(Market& market) {

	char inputC;
	int inputI;
	int inputI2;
	std::vector<int> mktCards;	//market cards to take in an exchange
	std::vector<int> plrCards;	//player cards to give in an exchange, or to sell

	int numCamels;

	while (1) {
		market.printMarket();
		hand.printHand();
		cout << name << ", pick a move: (T)ake, (E)xchange, (S)ell: ";
	        cin >> inputC;
		
		cout << "Enter -1 at any time to cancel and pick a new move." << endl << endl;

		if (inputC == 'T') {
			cout << "Which card do you want to take?: ";
			cin >> inputI;
			if (inputI == -1)
				continue;
			if (inputI < 0 || inputI >= 5) {
				cout << "Invalid market index" << endl;
				continue;
			}
			if (hand.handSize() == 7 && !(market.getCard(inputI)->isCamel())) {
				cout << "You've already reached the maximum hand size" << endl;
				continue;
			}
			return new Take(market, hand, inputI);
		} else if (inputC == 'E') {
			numCamels = 0;

			cout << "How many items would you like to exchange?: ");
			cin >> inputI;

                        cout << "Enter items from the market (integers, space separated): ";
                        for (int j = 0; j < inputI; j++) {
                                cin >> inputI2;
				if (inputI2 == -1)
					break;
                                if (inputI2 < 0 || inputI2 >= 5) {
                                        cout << "Invalid input" << endl;
                                        j--;    //try again, decrement loop counter.
                                        continue;
                                }

                                if (market.getCard(inputI2)->isCamel()) {
                                        cout << "You cannot exchange for camels from the market." << endl;
					j--;
                                        continue;
                                }

				mktCards.push_back(inputI2);
                        }

			cout << "Enter items from your hand (integers, space separated): ";
			for (int i = 0; i < inputI; i++) {
				cin >> inputI2;
				if (inputI2 == -1)
					break;
				if (inputI2 < 0 || inputI2 >= hand.handSize()) {
					cout << "Invalid input" << endl;
					i--;	//try again, decrement loop counter.
					continue;
				}
				if (hand.cardAt(inputI2)->isCamel())
					numCamels++;
				plrCards.push_back(inputI2);
			}

			if (inputI2 == -1)
				continue;

			if (hand.handSize() + numCamels > 7) {
				cout << "This exchange would result in you having too many goods (7 max)." << endl;
				continue;
			}

			return new Trade(market, hand, plrCards, mktCards);

		} else if (inputC == 'S') {
			cout << "How many items would you like to sell?: ";
			cin >> inputI;
			cout << "Enter items from your hand (integers, space separated): ";
			for (int k = 0; k < inputI; k++) {
				cin >> inputI2;
				if (inputI2 == -1)
					break;
				if (inputI2 < 0 || inputI2 >= hand.handSize()) {
					cout << "Invalid index." << endl;
					k--;
					continue;
				}
				plrCards.pushBack(inputI);
			}

			if (inputI2 == -1)
				continue;
			return new Sell(market, hand, plrCards);

		} else {
			cout << "Invalid Selection" << endl;
		}

	}
}

