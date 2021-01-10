//File that contains functions for the sprite class

//Libraries
#include "sprite.h"
#include "vertex.h"
#include <cstddef>

//Constructor
sprite::sprite() : _vboID(0) {
}

//Destructor
sprite::~sprite() {
    if (_vboID) {
        glDeleteBuffers(1, &_vboID);
    }
}

//Function to initialize the sprite
void sprite::initSprite(float x, float y, float width, float height) {
    //Set default values
    _x = x;
    _y = y;
    _width = width;
    _height = height;

    //Generate _vboID buffer it it isn't equalt to 0
    if (!(_vboID)) {
        glGenBuffers(1, &_vboID);
    }

    //Creating and setting up the data vertices
    vertex vertexData[6];

    for (int i = 0; i < 6; i++) {
        if ((i == 0) || (i == 4) || (i == 5)) {
            vertexData[i].pos.x = x + width;
        } else {
            vertexData[i].pos.x = x;
        }

        if ((i == 0) || (i == 1) || (i == 5)) {
            vertexData[i].pos.y = y + width;
        } else {
            vertexData[i].pos.y = y;
        }
    }

    //Set the entire entity color to magenta
    for (int i = 0; i < 6; i++) {
        vertexData[i].color.r = 255;
        vertexData[i].color.g = 0;
        vertexData[i].color.b = 255;
        vertexData[i].color.a = 255;
    }

    //Set top left corner to blue
    vertexData[1].color.r = 0;
    vertexData[1].color.g = 0;
    vertexData[1].color.b = 255;
    vertexData[1].color.a = 255;

    //Set bottom right corner to green
    vertexData[4].color.r = 0;
    vertexData[4].color.g = 255;
    vertexData[4].color.b = 0;
    vertexData[4].color.a = 255;

    glBindBuffer(GL_ARRAY_BUFFER, _vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    return;
}

//Function to draw sprite
void sprite::drawSprite() {
    //Bind buffer to object
    glBindBuffer(GL_ARRAY_BUFFER, _vboID);

    glEnableVertexAttribArray(0);
    
    //Position attribute pointer
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, pos));
    //Color attribute pointer
    glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(vertex), (void*)offsetof(vertex, color));
    
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glDisableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    return;
}
