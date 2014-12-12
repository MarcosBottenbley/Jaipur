#ifndef INVALIDMOVEEX_H
#define INVALIDMOVEEX_H

#include <iostream>
#include <exception>

class InvalidMoveEx: public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "ERROR: Invalid move";
	}

};
#endif
