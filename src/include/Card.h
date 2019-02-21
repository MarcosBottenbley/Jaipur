/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#pragma once

#include <string>

class Card
{
public:
    Card (std::string);

    std::string get_type ();
    bool is_camel ();
private:
    std::string type;
};
