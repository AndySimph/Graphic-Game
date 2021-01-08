//Programmer: Andy Simphaly

//Compile command
//g++ *.cpp -lSDL2 -lGLEW -lGL
//g++ *.cpp -lSDL2 -lGLEW -lGL -lglut

//Libraries
//#include <iostream>
#include "game.h"

int main (int argc, char** argv) {
    //Declare and run game
    game mainGame;
    mainGame.run();

    // std::cout<<"what"<<std::endl;
    // int a;
    // std::cin>>a;

    return 0;
}