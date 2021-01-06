
#include "game.h"

game::game() {
    _window = nullptr;
    _screenWidth = 1024;
    _screenHeight = 768;
}

game::~game() {

}

void game::run() {
    initSystems();
}

void game::initSystems() {
    //Initialize SDL
    SDL_Init(SDL_INIT_EVERYTHING);

    //Create window with title,x position, y position, window width, height, and open
    _window = SDL_CreateWindow("Graphics Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);
}


        