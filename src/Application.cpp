#include "Application.h"

#include <cstdlib>
#include <ctime>

int Application::window_width = 0;
int Application::window_height = 0;

const char* Application::TITLE = "Jaipur";

SDL_Window* Application::window = nullptr;
SDL_Renderer* Application::renderer = nullptr;


bool Application::init (int width, int height)
{
    std::srand (std::time(0));
    window_width = width;
    window_height = height;

    SDL_Init (SDL_INIT_VIDEO);
    const char *ERROR_MESSAGE = "Jaipur encountered an error: %s\n";

    window = SDL_CreateWindow
    (
        TITLE,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        window_width,
        window_height,
        0
    );

    if (window == NULL)
    {
        printf (ERROR_MESSAGE, SDL_GetError ());
        return false;
    }

    renderer = SDL_CreateRenderer (window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL)
    {
        printf (ERROR_MESSAGE, SDL_GetError ());
        return false;
    }

    return true;
}

void Application::quit ()
{
    if (window)
    {
        SDL_DestroyWindow (window);
    }
    if (renderer)
    {
        SDL_DestroyRenderer (renderer);
    }
    SDL_Quit ();
}
