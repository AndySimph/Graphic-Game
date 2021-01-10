//File that contains functions for the game class

//Libraries
#include "game.h"

//Main game function
game::game() : _window(nullptr), 
                _screenWidth(1024), 
                _screenHeight(768), 
                _gameState(gameState::PLAY), 
                _time(0.0f) {
}

//Deconstructor
game::~game() {

}

//function to run the game 
void game::run() {
    initSystems();

    //Initialize the test sprite
    _sprite.initSprite(-1.0, -1.0, 2.0, 2.0);

    //Load texture
    _playerTexture = ImgLoader::LoadPNG("Textures/JimmyJump_pack/PNG/Bubble_Big.png");

    //Loops until game has ended
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

    //Set up GL error
    GLenum error = glewInit();

    //Error checking
    if (error != GLEW_OK) {
        fatalError("Could not initialize GLEW.");
    }

    //Draw two windows so there won't be flickering, making the windows much smoother in transition
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    //Set background of window
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    //function call to initialize shaders
    initShaders();

    return;
}

//Function to initialize shaders
void game::initShaders() {
    //Compile, add and link the shaders
    _colorProg.compileShaders("Shaders/colorShading.vert", "Shaders/colorShading.frag");
    _colorProg.addAttribute("vertexPos");
    _colorProg.addAttribute("vertexColor");
    _colorProg.addAttribute("vertexUV");
    _colorProg.linkShaders();
}

//Function to loop the game
void game::gameLoop() {
    
    while (_gameState != gameState::EXIT) {
        //Process input
        processInput();

        _time += 0.01;

        //Draw the board
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

            //Quit on release of mouse button for faster testing
            case SDL_MOUSEBUTTONUP:
                _gameState = gameState::EXIT;
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

    //Use the shaders
    _colorProg.enable();

    //Bind the texture
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _playerTexture.id);
    GLint textureLocation = _colorProg.getuniformLocation("textureSampler");
    glUniform1i(textureLocation, 0);

    //Set the time location using time
    GLuint timeLocation = _colorProg.getuniformLocation("time");
    glUniform1f(timeLocation, _time);

    //Draw the test sprite
    _sprite.drawSprite();

    //Unbind the texture
    glBindTexture(GL_TEXTURE_2D, 0);

    //Disable the shaders
    _colorProg.disable();

    //Swap the Gl windows to window
    SDL_GL_SwapWindow(_window);

    return;
}