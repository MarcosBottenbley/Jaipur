/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#ifndef HUMAN_H
#define HUMAN_H
#include "Move.h"
#include "Take.h"
#include "Trade.h"
#include "Sell.h"
#include "Player.h"
#include <string>


class Human : public Player {
    void sortVector(std::vector<int>);
public:
    Human();
    Human(std::string name);
    virtual ~Human();
    Move* getMove(Market &market, Bank &bank);

private:
    Take* take(Market &market);
    Trade* trade(Market &market);
    Sell* sell(Market &market, Bank &bank);
    void printMktSelections(Market& market, bool arr[]);
    void printPlrSelections(bool arr[], int camels);
};

#endif
