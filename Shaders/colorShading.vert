#version 130
//Vertex shader operates on each vertex

//Input data from the VBO, each vertex is 2 floats
in vec2 vertexPos;

in vec4 vertexColor;
out vec4 fragColor;

void main() {
    //Set x and y position on screen
    gl_Position.xy = vertexPos;

    //Since we are in 2D, Z is 0
    gl_Position.z = 0.0;

    //Indicate that the coordinates are normalized
    gl_Position.w = 1.0;

    fragColor = vertexColor;
}