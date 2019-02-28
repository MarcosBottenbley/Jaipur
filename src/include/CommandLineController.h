#pragma once

#include <SDL.h>
#include<iostream>
#include <string>

class CommandLineController
{
public:
    bool get_commandline_input(std::string& input);
    bool get_commandline_input(char& input);
    bool get_commandline_input(int& input);
};
