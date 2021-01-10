//Header files for vertex

//Libraries
#include <GL/glew.h>
#pragma once

//Struct for positions
    struct Pos {
        float x;
        float y;
    };

//Struct for color, 4 bytes for Red, Green, Blue, and Alpha(padding)
    struct Color {
        GLubyte r;
        GLubyte g;
        GLubyte b;
        GLubyte a;
    };

struct vertex {
    Pos pos;
    Color color;

};