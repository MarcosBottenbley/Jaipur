/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#include <iostream>
#include "Human.h"

Human::Human() : Player()
{}

Human::Human(std::string hname) : Player(hname)
{}

Human::~Human()
{}

Move* Human::get_move(Market& market, Bank& bank)
{
    char inputC;
    Move* movePtr = 0;

    std::cout << std::endl;
    std::cout << hand << std::endl;
    market.printMarket();

    while (1)
    {
        std::cout << name << ", pick a move: (T)ake, (E)xchange, (S)ell, (P)rint Board: ";
        std::cin >> inputC;

        inputC = tolower(inputC);
        switch (inputC)
        {
            case 'p':
                market.printMarket();
                bank.print_bank();
                std::cout << std::endl;
                break;
            std::cout << "Enter -1 at any time to cancel and pick a new move.";
            std::cout << std::endl;
            case 't':
                movePtr = this->take(market);
                break;
            case 'e':
                movePtr = this->trade(market);
                break;
            case 's':
                movePtr = this->sell(market, bank);
                break;
            default:
                std::cout << "Invalid Selection" << std::endl;
                break;
        }

        if (movePtr != 0)
        {
            std::cin.ignore(256, '\n');
            return movePtr;
        }
    }
}

/*
 * PRIVATE FUNCTIONS
 */
Take* Human::take(Market &market)
{
    int inputI;

    while (1)
    {
        std::cout << "Which card do you want to take? (integer selection): ";
        std::cin >> inputI;
        if (std::cin.fail())
        {
            std::cout << "Your selection was not an integer." << std::endl;
            std::cin.clear();
            std::cin.ignore(10, '\n');
            continue;
        }

        if (inputI == -1)
        {
            return 0;
        }
        else if (inputI < 0 || inputI > 5)
        {
            std::cout << "Invalid entry" << std::endl;
            continue;
        }
        if (hand.get_hand_size() == 7 && !(market.getCard(inputI)->isCamel()))
        {
            std::cout << "You've already reached the maximum hand size" << std::endl;
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

    std::cout << "Enter items from the market (integers, space separated)";
    std::cout << std::endl << "Enter 0 to finish, 9 to see your selections: ";
    while (1) {
        std::cin >> inputI;
        if (std::cin.fail()) {
            std::cout << "Your selection was not an integer." << std::endl;
            std::cin.clear();
            std::cin.ignore(10, '\n');
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
            std::cout << "Invalid input" << std::endl;
            continue;
        }
        if (market.getCard(inputI-1)->isCamel()) {
            std::cout << "You cannot exchange for camels from the market." << std::endl;
            continue;
        }
        mktCards[inputI-1] = ! (mktCards[inputI-1]);        //toggle
    }

    std::cout << "Enter items from your hand (integers, space separated)";
    std::cout << std::endl << "Enter 8 to add a camel, -8 to remove a camel";
    std::cout << std::endl << "Enter 0 to finish, 9 to see your selections: ";
    while (1) {
        std::cin >> inputI;
        if (std::cin.fail()) {
            std::cout << "Your selection was not an integer." << std::endl;
            std::cin.clear();
            std::cin.ignore(10, '\n');
            continue;
        }

        if (inputI == -1)
            return 0;
        if (inputI == 0)
            break;
        if (inputI == 9) {
            std::cout << hand << std::endl;
            printMktSelections(market, mktCards);
            printPlrSelections(plrCards, numCamels);
            continue;
        }
        if (inputI == 8 && numCamels < (int)hand.get_herd_size()) {
            numCamels++;
            continue;
        }
        if (inputI == -8 && numCamels > 0) {
            numCamels--;
            continue;
        }
        if (inputI < 0 || inputI > (int)hand.get_hand_size()) {
            std::cout << "Invalid input" << std::endl;
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

    std::cout << "Enter items from your hand (integers, space separated)";
    std::cout << std::endl << "Enter 0 to finish, 9 to see your selections: ";
    while (1)
    {
        std::cin >> inputI;
        if (std::cin.fail())
        {
            std::cout << "Your selection was not an integer." << std::endl;
            std::cin.clear();
            std::cin.ignore(10, '\n');
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
            std::cout << hand << std::endl;
            printPlrSelections(plrCards, 0);
            continue;
        }
        else if (inputI < 0 || inputI > (int)hand.get_hand_size())
        {
            std::cout << "Invalid input" << std::endl;
            continue;
        }
        plrCards[inputI-1] = !(plrCards[inputI-1]);
    }
    return new Sell(market, hand, bank, plrCards);
}

void Human::printMktSelections(Market& market, bool arr[])
{
    std::cout << "You've selected these market cards: ";
    for (int i = 0; i < 5; i++)
    {
        if (arr[i])
        {
            std::cout << "[" << market.getCard(i)->getType() << "] ";
        }
    }
    std::cout << std::endl;
}

void Human::printPlrSelections(bool arr[], int camels)
{
    int size = (int)hand.get_hand_size();
    std::cout << "You've selected these cards from your hand: ";
    for (int i = 0; i < size; i++)
    {
        if (arr[i])
        {
            std::cout << "[" << hand.cardAt(i)->getType() << "] ";
        }
    }
    if (camels != 0)
    {
        std::cout << "and " << camels << " camels.";
    }
    std::cout << std::endl;
}

