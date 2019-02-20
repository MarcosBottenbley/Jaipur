#include "InputManager.h"

InputManager::InputManager()
{}

InputManager::~InputManager()
{}

InputManager* InputManager::GetInstance()
{
    if (instance == NULL)
    {
        instance = new InputManager();
    }
    return instance;
}

void InputManager::ReleaseInstance()
{
    if (instance)
    {
        delete instance;
    }
    instance = NULL;
}

//TODO: use a better way of getting command line input
//for the different types and check for invalid types
void GetCommandLineInput(std::string& input)
{
    std::cin >> input;
}

void GetCommandLineInput(char& input)
{
    std::cin >> input;
}

void GetCommandLineInput(int& input)
{
    std::cin >> input;
}
