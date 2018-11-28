/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#ifndef TRADE_H
#define TRADE_H

#include "Move.h"

class Trade : public Move
{
    private:
        std::vector<int> pIndexes;
        std::vector<int> mIndexes;
        int camels;
    public:
        Trade(Market &, Hand &, bool *, bool *, int);
        virtual ~Trade();
        int makeMove();
};
#endif
