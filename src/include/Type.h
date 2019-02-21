/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#ifndef TYPE_H
#define TYPE_H

#include <string>

class Type
{
    private:
        std::string s_type;
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
        
        Enum get_enum();
        std::string get_string();
        bool is_bonus();
        bool is_precious();
        
        //overloaded assignment operator
        void operator= (const std::string &);
        void operator= (Enum);
        
        //overloaded comparison operators
        bool operator== (const std::string &) const;
        bool operator== (const Enum);
        
    private:
        Enum from_string(std::string);
        std::string to_string(Enum);
};
#endif
