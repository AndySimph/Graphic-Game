//Header file for sprite class

//Libraries
#include <GL/glew.h>

#pragma once

class sprite {
    public:
        sprite();
        ~sprite();

        void initSprite(float x, float y, float width, float height);
        void drawSprite();

    private:
        int _x;
        int _y;
        int _width;
        int _height;

        //32 bit unsigned int given using GL
        GLuint _vboID;

};