#pragma once

#include <SDL.h>
#include<iostream>
#include <string>

class InputManager
{
public:
    static InputManager* get_instance();
    static void release_instance();

    void get_commandline_input(std::string& input);
    void get_commandline_input(char& input);
    void get_commandline_input(int& input)
private:
    static InputManager* instance = NULL;
private:
    InputManager();
    ~InputManager();
};
