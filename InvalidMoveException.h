#ifndef INVALIDMOVEEXCEPTION_H
#define INVALIDMOVEEXCEPTION_H

#include <iostream>
#include <exception>

class InvalidMoveException: public std::exception
{
	virtual const char* what() const throw()
	{
		return "ERROR: Invalid move";
	}

}InvalidMoveException;
#endif
