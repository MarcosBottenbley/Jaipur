/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#include <iostream>
#include "Human.h"

using std::cout;
using std::cin;
using std::endl;

Human::Human() : Player()
{}

Human::Human(std::string hname) : Player(hname)
{}

Human::~Human()
{}

Move* Human::getMove(Market& market, Bank& bank)
{
    char inputC;
    Move* movePtr = 0;

    cout << endl;
    hand.printHand();
    market.printMarket();

    while (1)
    {
        cout << name << ", pick a move: (T)ake, (E)xchange, (S)ell, (P)rint Board: ";
        cin >> inputC;

        if (tolower(inputC) != 'p')
        {
            cout << "Enter -1 at any time to cancel and pick a new move.";
        }
        cout << endl;

        if (tolower(inputC) == 't')
        {
            movePtr = take(market);
        }
        else if (tolower(inputC) == 'e')
        {
            movePtr = trade(market);
        }
        else if (tolower(inputC) == 's')
        {
            movePtr = sell(market, bank);
        }
        else if (tolower(inputC)  == 'p')
        {
            printStats();
            market.printMarket();
            bank.printBank();
            cout << endl;
            continue;
        }
        else
        {
            cout << "Invalid Selection" << endl;
        }

        if (movePtr != 0)
        {
            cin.ignore(256, '\n');
            return movePtr;
        }
    }
}

Take* Human::take(Market &market)
{
    int inputI;

    while (1)
    {
        cout << "Which card do you want to take? (integer selection): ";
        cin >> inputI;
        if (cin.fail())
        {
            cout << "Your selection was not an integer." << endl;
            cin.clear();
            cin.ignore(10, '\n');
            continue;
        }

        if (inputI == -1)
        {
            return 0;
        }
        else if (inputI < 0 || inputI > 5)
        {
            cout << "Invalid entry" << endl;
            continue;
        }
        if (hand.getHandSize() == 7 && !(market.getCard(inputI)->isCamel()))
        {
            cout << "You've already reached the maximum hand size" << endl;
            continue;
        }
        return new Take(market, hand, inputI-1);
    }
}

Trade* Human::trade(Market &market)
{
    int inputI;
    int numCamels = 0;
    bool mktCards[5] {0};       //initializes to false
    bool plrCards[7] {0};

    cout << "Enter items from the market (integers, space separated)";
    cout << endl << "Enter 0 to finish, 9 to see your selections: ";
    while (1) {
        cin >> inputI;
        if (cin.fail()) {
            cout << "Your selection was not an integer." << endl;
            cin.clear();
            cin.ignore(10, '\n');
            continue;
        }

        if (inputI == -1)
            return 0;
        if (inputI == 0)
            break;
        if (inputI == 9) {
            market.printMarket();
            printMktSelections(market, mktCards);
            continue;
        }
        else if (inputI < -1 || inputI > 5) {
            cout << "Invalid input" << endl;
            continue;
        }
        if (market.getCard(inputI-1)->isCamel()) {
            cout << "You cannot exchange for camels from the market." << endl;
            continue;
        }
        mktCards[inputI-1] = ! (mktCards[inputI-1]);        //toggle
    }

    cout << "Enter items from your hand (integers, space separated)";
    cout << endl << "Enter 8 to add a camel, -8 to remove a camel";
    cout << endl << "Enter 0 to finish, 9 to see your selections: ";
    while (1) {
        cin >> inputI;
        if (cin.fail()) {
            cout << "Your selection was not an integer." << endl;
            cin.clear();
            cin.ignore(10, '\n');
            continue;
        }

        if (inputI == -1)
            return 0;
        if (inputI == 0)
            break;
        if (inputI == 9) {
            hand.printHand();
            printMktSelections(market, mktCards);
            printPlrSelections(plrCards, numCamels);
            continue;
        }
        if (inputI == 8 && numCamels < (int)hand.getHerdSize()) {
            numCamels++;
            continue;
        }
        if (inputI == -8 && numCamels > 0) {
            numCamels--;
            continue;
        }
        if (inputI < 0 || inputI > (int)hand.getHandSize()) {
            cout << "Invalid input" << endl;
            continue;
        }
        plrCards[inputI-1] = !(plrCards[inputI-1]);
    }

    /*if (hand.handSize() + numCamels > 7) {
        cout << "This exchange would result in you having too many goods (7 max)." << endl;
        return 0;
    }*/

    return new Trade(market, hand, plrCards, mktCards, numCamels);
}

Sell* Human::sell(Market &market, Bank &bank)
{
    int inputI;
    bool plrCards[7] {0};

    cout << "Enter items from your hand (integers, space separated)";
    cout << endl << "Enter 0 to finish, 9 to see your selections: ";
    while (1)
    {
        cin >> inputI;
        if (cin.fail())
        {
            cout << "Your selection was not an integer." << endl;
            cin.clear();
            cin.ignore(10, '\n');
            continue;
        }
        if (inputI == -1)
        {
            return 0;
        }
        if (inputI == 0)
        {
            break;
        }
        if (inputI == 9)
        {
            hand.printHand();
            printPlrSelections(plrCards, 0);
            continue;
        }
        else if (inputI < 0 || inputI > (int)hand.getHandSize())
        {
            cout << "Invalid input" << endl;
            continue;
        }
        plrCards[inputI-1] = !(plrCards[inputI-1]);
    }
    return new Sell(market, hand, bank, plrCards);
}

void Human::printMktSelections(Market& market, bool arr[])
{
    cout << "You've selected these market cards: ";
    for (int i = 0; i < 5; i++)
    {
        if (arr[i])
        {
            cout << "[" << market.getCard(i)->getType() << "] ";
        }
    }
    cout << endl;
}

void Human::printPlrSelections(bool arr[], int camels)
{
    int size = (int)hand.getHandSize();
    cout << "You've selected these cards from your hand: ";
    for (int i = 0; i < size; i++)
    {
        if (arr[i])
        {
            cout << "[" << hand.cardAt(i)->getType() << "] ";
        }
    }
    if (camels != 0)
    {
        cout << "and " << camels << " camels.";
    }
    cout << endl;
}

