#include "Token.h"

Token::Token() {
	type = "NoType";
	value = 0;
}

Token::Token(string s, int v) {
	type = s;
	value = v;
}

std::string Token::getType() {
	return type;
}

int Token::getValue() {
	return value;
}
