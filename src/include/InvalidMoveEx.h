/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#ifndef INVALIDMOVEEX_H
#define INVALIDMOVEEX_H

#include <iostream>
#include <exception>
#include <string>

class InvalidMoveEx: public std::exception
{
    const char* errMessage;
public:
    InvalidMoveEx() {
        errMessage = "ERROR: Invalid move";
    }

    InvalidMoveEx(const char* str) {
        errMessage = str;
    }

    virtual const char* what() const throw()
    {
        return errMessage;
    }

};
#endif
