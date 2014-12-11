#ifndef TYPE_H
#define TYPE_H

#include <string>

class Type
{
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
		Enum getEnum();
		std::string getString();
	private:
		std::string s_type;
		int value;
		Enum e;
		Enum fromString(std::string);
		std::string toString(Enum);
};
#endif
