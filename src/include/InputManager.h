#pragma once

#include <SDL.h>
#include<iostream>
#include <string>

class InputManager
{
public:
    static InputManager* GetInstance();
    static void ReleaseInstance();

    void GetCommandLineInput(std::string& input);
    void GetCommandLineInput(char& input);
    void GetCommandLineInput(int& input)
private:
    static InputManager* instance = NULL;
private:
    InputManager();
    ~InputManager();
};
