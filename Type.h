#ifndef TYPE_H
#define TYPE_H

#include <string>

class Type
{
	private:
		std::string s_type;
		int value
		Enum fromString(std::string);
		std::string toString(Enum);
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
};
#endif
