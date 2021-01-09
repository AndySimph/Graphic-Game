//Header files for vertex

//Libraries
#include <GL/glew.h>
#pragma once

struct vertex {
    //Struct for positions
    struct Pos {
        float x;
        float y;
    } pos;

    //Struct for color, 4 bytes for Red, Green, Blue, and Alpha(padding)
    struct Color {
        GLubyte r;
        GLubyte g;
        GLubyte b;
        GLubyte a;
    } color;

};