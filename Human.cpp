#include <iostream>
#include "Human.h"

using std::cout;
using std::cin;
using std::endl;

Human::Human() {
	wins = 0;
}

Human::Human(std::string hname) {		//TODO: is this stuff necessary? it's in Player.cpp already
    name = hname;
    score = 0;
    wins = 0;
}

Human::~Human()
{}

Move* Human::getMove(Market& market, Bank& bank) {
	char inputC;
	Move* movePtr;

	while (1) {
		market.printMarket();
		hand.printHand();
		cout << name << ", pick a move: (T)ake, (E)xchange, (S)ell: ";
		cin >> inputC;

		cout << "Enter -1 at any time to cancel and pick a new move." << endl << endl;

		if (inputC == 'T') {
			movePtr = take(market);
		} else if (inputC == 'E') {
			movePtr = trade(market);
		} else if (inputC == 'S') {
			movePtr = sell(market, bank);
		} else {
			cout << "Invalid Selection" << endl;
		}

		if (movePtr != 0)
			return movePtr;
	}
}

	Take* Human::take(Market &market) {
		int inputI;

		while (1) {
			cout << "Which card do you want to take? (integer selection): ";
			cin >> inputI;
			if (inputI == -1)
				return 0;
			if (inputI < 0 || inputI >= 5) {
				cout << "Invalid entry";
				continue;
			}
			if (hand.handSize() == 7 && !(market.getCard(inputI)->isCamel())) {
				cout << "You've already reached the maximum hand size" << endl;
				continue;
			}
			return new Take(market, hand, inputI);
		}
	}

	Trade* Human::trade(Market &market) {
		int inputI;
		int numCamels = 0;
		bool mktCards[5] {0};		//initializes to false
		bool plrCards[7] {0};

		cout << "Enter items from the market (integers, space separated)";
		cout << endl << "Enter 0 to finish, 9 to see your selections: ";
		while (1) {
			cin >> inputI;
			if (inputI == -1)
				return 0;
			if (inputI == 0)
				break;
			if (inputI == 9) {
				market.printMarket();
				printMktSelections(market, mktCards);
			}
			else if (inputI < -1 || inputI > 5) {
				cout << "Invalid input" << endl;
				continue;
			}
			if (market.getCard(inputI)->isCamel()) {
				cout << "You cannot exchange for camels from the market." << endl;
				continue;
			}
			mktCards[inputI-1] = ! (mktCards[inputI-1]);		//toggle
		}

		cout << "Enter items from your hand (integers, space separated)";
		cout << endl << "Enter 8 to add a camel, -8 to remove a camel";
		cout << endl << "Enter 0 to finish, 9 to see your selections: ";
		while (1) {
			cin >> inputI;
			if (inputI == -1)
				return 0;
			if (inputI == 0)
				break;
			if (inputI == 9) {
				hand.printHand();
				printMktSelections(market, mktCards);
				printPlrSelections(market, plrCards, numCamels);
			}
			if (inputI == 8 && numCamels < (int)hand.herdSize())
				numCamels++;
			else if (inputI == -8 && numCamels > 0)
				numCamels--;
			else if (inputI < 0 || inputI > (int)hand.handSize()) {
				cout << "Invalid input" << endl;
				continue;
			}
			plrCards[inputI-1] = !(plrCards[inputI-1]);
		}

		if (hand.handSize() + numCamels > 7) {
			cout << "This exchange would result in you having too many goods (7 max)." << endl;
			return 0;
		}

		return new Trade(market, hand, plrCards, mktCards);
	}

	Sell* Human::sell(Market &market, Bank &bank) {
		int inputI;
		bool plrCards[7] {0};

		cout << "Enter items from your hand (integers, space separated)";
		cout << endl << "Enter 0 to finish, 9 to see your selections: ";
		while (1) {
			cin >> inputI;
			if (inputI == -1)
				return 0;
			if (inputI == 0)
				break;
			if (inputI == 9) {
				hand.printHand();
				printPlrSelections(market, plrCards, 0);
			}
			else if (inputI < 0 || inputI > (int)hand.handSize()) {
				cout << "Invalid input" << endl;
				continue;
			}
			plrCards[inputI-1] = !(plrCards[inputI-1]);
		}

		return new Sell(market, hand, bank, plrCards);
	}

	void Human::printMktSelections(Market& market, bool arr[]) {
		cout << "You've selected these market cards: ";
		for (int i = 0; i < 5; i++)
        {
			if (arr[i])
				cout << "[" << market.getCard(i)->getType() << "] ";
        }
            cout << endl;
	}

	void Human::printPlrSelections(Market& market, bool arr[], int camels) {
		int size = (int)hand.handSize();
		cout << "You've selected these cards from your hand: ";
		for (int i = 0; i < size; i++)
        {
			if (arr[i])
				cout << "[" << hand.cardAt(i)->getType() << "] ";
        }
		if (camels != 0)
			cout << "and " << camels << " camels.";
		cout << endl;
	}

