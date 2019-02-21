/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#include "Token.h"

Token::Token ()
{
    type = "NoType";
    value = 0;
}

Token::Token (std::string s, int v)
{
    type = s;
    value = v;
}

std::string Token::get_type ()
{
    return type;
}

int Token::get_value ()
{
    return value;
}
