//Function file for the IOManager class

//Libraries
#include "IOManager.h"
#include <fstream>

//Constructor
// IOManager::IOManager() {

// }

//Destructor
// IOManager::~IOManager() {

// }

bool IOManager::readFileToBuffer(std::string filePath, std::vector<char>& buffer) {

    //Set file stream and error check
    std::ifstream file(filePath, std::ios::binary);
    if (file.fail()) {
        perror(filePath.c_str());
        return false;
    }

    //Seek to the end
    file.seekg(0, std::ios::end);

    //Get file size
    int fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    //Ignore file header bytes
    fileSize -= file.tellg();

    //Read in file
    buffer.reserve(fileSize);
    file.read(&(buffer[0]), fileSize);

    //Close file
    file.close();

    return true;
}