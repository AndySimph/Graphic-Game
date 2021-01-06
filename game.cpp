
#include "game.h"
#include <iostream>

game::game() {
    _window = nullptr;
    _screenWidth = 1024;
    _screenHeight = 768;
    _gameState = gameState::PLAY;
}

//Deconstructor
game::~game() {

}

//function to run the game 
void game::run() {
    initSystems();

    gameLoop();
}

//Initialize the system
void game::initSystems() {
    //Initialize SDL
    SDL_Init(SDL_INIT_EVERYTHING);

    //Create window with title,x position, y position, window width, height, and open
    _window = SDL_CreateWindow("Graphics Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);
}

void game::gameLoop() {
    
    while (_gameState != gameState::EXIT) {

        processInput();
    }
}

void game::processInput() {
    //Initialize event
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                _gameState = gameState::EXIT;
                break;
            case SDL_MOUSEMOTION:
                std::cout<<event.motion.x<<" "<<event.motion.y<< std::endl;
                break;
        }

    }
}
        
        