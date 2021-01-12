//File that contains functions for the game class

//Libraries
#include "game.h"

//Main game function
game::game() : _screenWidth(1024), 
                _screenHeight(768), 
                _gameState(gameState::PLAY), 
                _time(0.0f), 
                _maxFps(60.0f) {
    _cam.init(_screenWidth, _screenHeight);
}

//Deconstructor
game::~game() {

}

//function to run the game 
void game::run() {
    initSystems();

    //Initialize the test sprite
    _sprites.push_back(new sprite());
    _sprites.back()->initSprite(0.0, 0.0, _screenWidth/2, _screenWidth/2, "Textures/JimmyJump_pack/PNG/Bubble_Big.png");

    _sprites.push_back(new sprite());
    _sprites.back()->initSprite(_screenWidth/2, 0.0, _screenWidth/2, _screenWidth/2, "Textures/JimmyJump_pack/PNG/Bubble_Big.png");

    //Loops until game has ended
    gameLoop();
}

//Initialize the system
void game::initSystems() {

    //Initialize the engine
    init();

    //Create window
    _window.create("Game Engine", _screenWidth, _screenHeight, 0);

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

        //Used for frame time measuring
        float startTicks = SDL_GetTicks();

        //Process input
        processInput();

        //Increment time
        _time += 0.01;

        //Update camera
        _cam.update();

        //Draw the board
        draw();

        //Calculate fps
        calculateFPS();
        
        //Print once every 10 frames
        static int frameCounter = 0;
        frameCounter++;
        if (frameCounter == 10) {
            std::cout << _fps <<std::endl;
            frameCounter = 0;
        }

        float frameTicks = SDL_GetTicks() - startTicks;

        //Limit the max fps
        if ((1000.0f / _maxFps) > frameTicks) {
            SDL_Delay((1000.0f / _maxFps) - frameTicks);
        }

    }

    return;
}

//Function to process user input
void game::processInput() {
    //Initialize event
    SDL_Event event;

    const float CAMSPEED = 20;
    const float SCALESPEED = 0.1f;

    //While loop while an event is happening within the window
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            //Event if window is quit
            case SDL_QUIT:
                _gameState = gameState::EXIT;
                break;

            //Record mouse motion within the window
            case SDL_MOUSEMOTION:
                //std::cout<<event.motion.x<<" "<<event.motion.y<< std::endl;
                break;

            //Switch case for different keyboard presses
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    
                    //Move the camera up if w is pressed
                    case SDLK_w:
                        _cam.setPos(_cam.getPos() + glm::vec2(0.0, CAMSPEED));
                        break;

                    //Move the camera down if s is pressed
                    case SDLK_s:
                        _cam.setPos(_cam.getPos() + glm::vec2(0.0, -CAMSPEED));
                        break;

                    //Move the camera right if d is pressed
                    case SDLK_d:
                        _cam.setPos(_cam.getPos() + glm::vec2(CAMSPEED, 0.0));
                        break;

                    //Move the camera left if a is pressed
                    case SDLK_a:
                        _cam.setPos(_cam.getPos() + glm::vec2(-CAMSPEED, 0.0));
                        break;

                    //Move the camera left if a is pressed
                    case SDLK_q:
                        _cam.setScale(_cam.getScale() + SCALESPEED);
                        break;

                    //Move the camera left if a is pressed
                    case SDLK_e:
                        _cam.setScale(_cam.getScale() - SCALESPEED);
                        break;

                }
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
    GLint textureLocation = _colorProg.getuniformLocation("textureSampler");
    glUniform1i(textureLocation, 0);

    //Set the time location using time
    GLuint timeLocation = _colorProg.getuniformLocation("time");
    glUniform1f(timeLocation, _time);

    //Set the camera matrix
    GLuint pLocation = _colorProg.getuniformLocation("p");
    glm::mat4 cameraMatrix = _cam.getCam();

    glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));

    //Draw the test sprite
    for (int i = 0; i < _sprites.size(); i++) {
        _sprites[i]->drawSprite();
    }

    //Unbind the texture
    glBindTexture(GL_TEXTURE_2D, 0);

    //Disable the shaders
    _colorProg.disable();

    //Swap the Gl windows to window
    _window.swapBuffer();

    return;
}

//Function to calculate fps
void game::calculateFPS() {

    //Declare variables
    static const int NUM_SAMPLES = 10;
    static float frameTimes[NUM_SAMPLES];
    static int currFrame = 0;
    static float prevTicks = SDL_GetTicks();

    //Get current ticks
    float currTicks = SDL_GetTicks();

    //Set current frametime
    _frametime = currTicks - prevTicks;
    frameTimes[currFrame % NUM_SAMPLES] = _frametime;

    //Set previous ticks to current
    prevTicks = currTicks;

    //increment current frame
    int count;
    currFrame++;

    //Check if count needs to be above or below num samples
    if (currFrame < NUM_SAMPLES) {
        count = currFrame;
    } else {
        count = NUM_SAMPLES;
    }

    //Calculate average frame time
    float frameTimeAvg = 0;
    for (int i = 0; i < count; i ++) {
        frameTimeAvg += frameTimes[i];
    }
    frameTimeAvg /= count;

    //Check and adjust fps according to average frame time
    if (frameTimeAvg) {
        _fps = 1000.0f / frameTimeAvg;
    } else {
        _fps = 60.0f;
    }

    return;
}

