#ifndef INVALIDMOVEEX_H
#define INVALIDMOVEEX_H

#include <iostream>
#include <exception>
#include <string>

class InvalidMoveEx: public std::exception
{
	std::string errMessage;
public:
	InvalidMoveEx() {
		errMessage = "ERROR: Invalid move";
	}

	InvalidMoveEx(std::string str) {
		errMessage = str;
	}

	virtual const char* what() const throw()
	{
		return errMessage;
	}

};
#endif
