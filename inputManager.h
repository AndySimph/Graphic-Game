//Header file for input manager class

//Libraries
#include <unordered_map>


class inputManager {
    public:
        //Constructor / Destructor
        inputManager();
        ~inputManager();

        void keypress(unsigned int keyID);
        void keyrelease(unsigned int keyID);

        bool iskeypressed(unsigned int keyID);

    private:
        std::unordered_map<unsigned int, bool> _keymap;

};