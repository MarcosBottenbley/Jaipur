#include "InputManager.h"

InputManager::InputManager()
{}

InputManager::~InputManager()
{}

InputManager* InputManager::get_instance()
{
    if (instance == NULL)
    {
        instance = new InputManager();
    }
    return instance;
}

void InputManager::release_instance()
{
    if (instance)
    {
        delete instance;
    }
    instance = NULL;
}

//TODO: use a better way of getting command line input
//for the different types and check for invalid types
void get_commandline_input(std::string& input)
{
    std::cin >> input;
}

void get_commandline_input(char& input)
{
    std::cin >> input;
}

void get_commandline_input(int& input)
{
    std::cin >> input;
}
