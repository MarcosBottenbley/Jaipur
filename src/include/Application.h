#pragma once

#include <SDL.h>

class Application
{
public:
    static int window_width;
    static int window_height;

    static SDL_Window *window;
    static SDL_Renderer *renderer;
public:
    static bool init (int width, int height);
    static void quit ();
private:
    static const char *TITLE;
};
