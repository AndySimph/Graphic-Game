//Header file for input manager class

//Libraries
#include <unordered_map>
#include <glm/glm.hpp>

class inputManager {
    public:
        //Constructor / Destructor
        inputManager();
        ~inputManager();

        void keypress(unsigned int keyID);
        void keyrelease(unsigned int keyID);

        bool iskeypressed(unsigned int keyID);

        //Setters
        void setMouseCoord(float x, float y);

        //Getters
        glm::vec2 getMouseCoord() const { return _mouseCoords; };

    private:
        std::unordered_map<unsigned int, bool> _keymap;
        glm::vec2 _mouseCoords;

};