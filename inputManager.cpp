//Functions for input manager class

//Libraries
#include "inputManager.h"

//Constructor
inputManager::inputManager() {

}

//Destructor
inputManager::~inputManager() {

}

//Function to interpret when a key is pressed
void inputManager::keypress(unsigned int keyID) {

    //Check if the keyID is in the map, if not create it and set it to true
    _keymap[keyID] = true;

    return;
}

//Function to interpret when a key is released
void inputManager::keyrelease(unsigned int keyID) {

    //Check if the keyID is in the map, if not create it and set it to false
    _keymap[keyID] = false;

    return;
}

//Function to check whether a key is pressed
bool inputManager::iskeypressed(unsigned int keyID) {

    //Set it to the value where keyID is
    auto it = _keymap.find(keyID);

    //Check if the ID is found
    if (it != _keymap.end()) {
        return it->second;
    }

    return false;
}
