//Header file for game class
//Libraries
#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <GL/gl.h>

#include "sprite.h"
#include "GLTexture.h"
#include "error.h"
#include "GLSLProgram.h"

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
        //Variables for the window
        SDL_Window* _window;
        int _screenWidth;
        int _screenHeight;

        gameState _gameState;

        std::vector<sprite*> _sprites;

        GLSLProgram _colorProg;

        float _time;

        float _fps;
        float _maxFps;
        float _frametime;

        //Functions
        void initSystems();
        void initShaders();
        void gameLoop();
        void processInput();
        void draw();
        void calculateFPS();

};