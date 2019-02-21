/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#include "Type.h"
#include <algorithm>

Type::Type()
{}

Type::Type(std::string s) : s_type(s)
{}

Type::Enum Type::from_string(std::string s)
{
    std::transform (s.begin(), s.end(), s.begin(), toupper);

    if(s == "DIAMOND")
        return Type::DIAMOND;
    else if(s == "GOLD")
        return Type::GOLD;
    else if(s == "SILVER")
        return Type::SILVER;
    else if(s == "CLOTH")
        return Type::CLOTH;
    else if(s == "SPICE")
        return Type::SPICE;
    else if(s == "LEATHER")
        return Type::LEATHER;
    else if(s == "BONUS3")
        return Type::BONUS3;
    else if(s == "BONUS4")
        return Type::BONUS4;
    else if(s == "BONUS5")
        return Type::BONUS5;
    else
        return Type::INVALIDTYPE;
}

std::string Type::to_string(Type::Enum t)
{
    switch (t)
    {
        case Type::DIAMOND: return "Diamond";
        case Type::GOLD: return "Gold";
        case Type::SILVER: return "Silver";
        case Type::CLOTH: return "Cloth";
        case Type::SPICE: return "Spice";
        case Type::LEATHER: return "Leather";
        case Type::BONUS3: return "Bonus3";
        case Type::BONUS4: return "Bonus4";
        case Type::BONUS5: return "Bonus5";
        case Type::INVALIDTYPE: return "INVALIDTYPE";
    }
    return "INVALIDTYPE";
}

Type::Enum Type::get_enum ()
{
    return from_string (s_type);
}

std::string Type::get_string ()
{
    return s_type;
}

void Type::operator= (const std::string &s)
{
    s_type = s;
}

void Type::operator= (const Type::Enum e)
{
    s_type = to_string (e);
}

bool Type::operator== (const std::string &s) const
{
    return (s_type == s);
}

bool Type::operator== (const Type::Enum e)
{
    return (s_type == to_string (e));
}

bool Type::is_bonus ()
{
    if(s_type == "Bonus3" || s_type == "Bonus4" || s_type == "Bonus5")
    {
        return true;
    }
    return false;
}

bool Type::is_precious ()
{
    if(s_type == "Gold" || s_type == "Silver" || s_type == "Diamond")
    {
        return true;
    }
    return false;
}
