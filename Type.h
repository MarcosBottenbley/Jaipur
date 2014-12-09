#ifndef TYPE_H
#define TYPE_H

#include <string>

class Type
{
	private:
		std::string s_type;
		int value;

	public:
		enum Enum
		{
			DIAMOND,
			GOLD,
			SILVER,
			CLOTH,
			SPICE,
			LEATHER,
			BONUS3,
			BONUS4,
			BONUS5,
			INVALIDTYPE
		};

		Type();
		Type(std::string);
		int getValue();
		std::string getString();
		Enum fromString(std::string);   //      I moved these two to public because they return/take Enum values
		std::string toString(Enum);     //      and there's no way to forward declare enums in C++ (as far as I know)
};
#endif
