//Libraries
#include <SDL2/SDL.h>
#include <GL/glew.h>

#pragma once

class game{
    public:
        game();
        ~game();

        void run();

        void initSystems();

    private:
        SDL_Window* _window;
        int _screenWidth;
        int _screenHeight;
};