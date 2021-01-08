#include "sprite.h"

//Constructor
sprite::sprite() {
    _vboID = 0;
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
    float vertexData[12];

    for (int i = 0; i < 12; i++) {
        if (i%2==0) {
            if ((i == 0) || (i == 8) || (i == 10)) {
                vertexData[i] = x + width;
            } else {
                vertexData[i] = x;
            }

        } else {
            if ((i == 1) || (i == 3) || (i == 11)) {
                vertexData[i] = y + height;
            } else {
                vertexData[i] = y;
            }
        }
    }

    glBindBuffer(GL_ARRAY_BUFFER, _vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    return;
}

//Function to draw sprite
void sprite::drawSprite() {
    glBindBuffer(GL_ARRAY_BUFFER, _vboID);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glDisableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    return;
}
