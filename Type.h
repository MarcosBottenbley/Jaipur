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
		Enum getEnum();
		std::string getString();
	private:
		Enum fromString(std::string);
		std::string toString(Enum);
};
#endif
