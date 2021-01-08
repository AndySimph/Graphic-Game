//Libraries
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include "sprite.h"
//#include <GL/glut.h>

#pragma once

//Enum of the game states
enum class gameState {PLAY, EXIT};

//game of class
class game{
    public:
        //Constructor and Destructor of game
        game();
        ~game();

        //Run function
        void run();

    private:
        void initSystems();
        void gameLoop();
        void processInput();
        void draw();

        SDL_Window* _window;
        int _screenWidth;
        int _screenHeight;

        gameState _gameState;

        sprite _sprite;
};