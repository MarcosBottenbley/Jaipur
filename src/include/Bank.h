/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#pragma once

#include "Token.h"
#include "Type.h"
#include <stack>
#include <cstdlib>
#include <ctime>

class Bank
{
public:
    Bank();
    Bank(int);
    ~Bank();

    std::stack<Token*> get_tokens (Type::Enum,int);
    void print_bank ();
    bool gameover ();
private:
    std::stack<Token*> bank[9];
private:
    void init_bank ();
    void shuffle (int *,int);
    void add_tokens (int *,int,Type);
};
