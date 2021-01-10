//Header file for the IOManager class

//Libraries
#include <vector>
#include <string>
#pragma once

class IOManager {
    public:
        // IOManager();
        // ~IOManager();

        static bool readFileToBuffer(std::string filePath, std::vector<char>& buffer);

    private:

};