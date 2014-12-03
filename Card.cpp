#include "Card.h"

Card::Card(std::string s) {
	type = s;
}

std::string Card::getType() {
	return type;
}

bool Card::isCamel() {
	if (type == "Camel")
		return true;
	return false;
}
