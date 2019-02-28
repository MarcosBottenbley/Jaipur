#include "CommandLineController.h"

bool CommandLineController::get_commandline_input(std::string& input)
{
    std::cin >> input;
    return true;
}

bool CommandLineController::get_commandline_input(char& input)
{
    std::cin >> input;
    return true;
}

bool CommandLineController::get_commandline_input(int& input)
{
    std::cin >> input;
    return true;
}
