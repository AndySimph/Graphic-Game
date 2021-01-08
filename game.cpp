
#include "game.h"
#include <iostream>
#include <string>

//Error function
void fatalError(std::string errorStr) {
    std::cout<<errorStr<<std::endl;
    std::cout<<"Enter any key to quit"<<std::endl;
    char temp;
    std::cin>>temp;

    SDL_Quit();

    return;
}

//Main game function
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

    //Error Checking
    if (_window == nullptr) {
        fatalError("SDL Window could not be created.");
    }

    //Create glContext
    SDL_GLContext glContext = SDL_GL_CreateContext(_window);

    //Error Checking
    if (glContext == nullptr) {
        fatalError("SDL_GL context could not be created.");
    }

    GLenum error = glewInit();

    //Error checking
    if (error != GLEW_OK) {
        fatalError("Could not initialize GLEW.");
    }

    //Draw two windows so there won't be flickering, making the windows much smoother in transition
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    //Set background of window
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    return;
}

//Function to loop the game
void game::gameLoop() {
    
    while (_gameState != gameState::EXIT) {

        processInput();

        draw();
    }

    return;
}

//Function to process user input
void game::processInput() {
    //Initialize event
    SDL_Event event;

    //While loop while an event is happening within the window
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            //Event if window is quit
            case SDL_QUIT:
                _gameState = gameState::EXIT;
                break;

            //Record mouse motion within the window
            case SDL_MOUSEMOTION:
                std::cout<<event.motion.x<<" "<<event.motion.y<< std::endl;
                break;
        }

    }

    return;
}

//Function to draw the game
void game::draw() {
    //Clear the current buffer
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.5f);    
    glVertex2f( 0.5f, -0.5f);
    glVertex2f( 0.5f,  0.5f);
    glVertex2f(-0.5f,  0.5f);
    glEnd();


    //Swap the Gl windows to window
    SDL_GL_SwapWindow(_window);

    return;
}