/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#pragma once

#include <iostream>
#include <exception>
#include <string>

class InvalidMoveEx: public std::exception
{
    const char* errMessage;
public:
    inline InvalidMoveEx() {
        errMessage = "ERROR: Invalid move";
    }

    inline InvalidMoveEx(const char* str) {
        errMessage = str;
    }

    inline virtual const char* message() const throw()
    {
        return errMessage;
    }

};
