/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#include "Card.h"

Card::Card (std::string s)
{
    type = s;
}

std::string Card::get_type ()
{
    return type;
}

bool Card::is_camel ()
{
    if (type == "Camel")
        return true;
    return false;
}
