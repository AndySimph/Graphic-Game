//Libraries
#include <SDL2/SDL.h>
#include <GL/glew.h>

#pragma once

enum class gameState {PLAY, EXIT};

class game{
    public:
        game();
        ~game();

        void run();

    private:
        void initSystems();
        void gameLoop();
        void processInput();

        SDL_Window* _window;
        int _screenWidth;
        int _screenHeight;

        gameState _gameState;
};