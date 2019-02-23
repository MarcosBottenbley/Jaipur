/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */
#pragma once

#include "Card.h"
#include "Hand.h"
#include "Market.h"
#include <exception>
#include <vector>
#include "InvalidMoveEx.h"  //TODO: do we need to change this back?

using std::vector;

class Move
{
public:
    Move(Market &,Hand &);
    virtual ~Move();
    virtual int make_move() = 0;
protected:
    Market &market;
    Hand &hand;
    vector<int> get_indexes(bool *, int);
};
