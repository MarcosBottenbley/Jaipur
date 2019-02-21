/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

/*  The Token class is used to represent each kind of token 
    (bonus, camel, etc.)
*/
#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class Token
{
private:
    std::string type;               //type of token (9 types in total, the 6 goods
                                    //and the 3 bonus types)
    int value;                      //how many rupees the token will yield at the
                                    //end of the round
public:
    Token();
    Token(std::string, int);                //constructor for Token
    std::string get_type();          //returns type
    int getValue();                 //returns the rupee value of the token
};
#endif
