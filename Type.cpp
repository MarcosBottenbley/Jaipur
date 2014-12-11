#include "Type.h"
#include <algorithm>

Type::Type()
{}

Type::Type(std::string s) : s_type(s)
{
	value = fromString(s);
	e = fromString(s);
}

Type::Enum Type::fromString(std::string s)
{
	std::transform(s.begin(), s.end(), s.begin(), toupper);
	
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

std::string Type::toString(Type::Enum t)
{
	switch(t)
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

