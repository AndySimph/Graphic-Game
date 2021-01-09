#version 130
//Fragment shader operates on each pixel in a given polygon

//Take in given vector colors
in vec4 fragColor;

//3 Component float vector that gets outputted to the screen for each pixel
out vec4 color;

void main() {
    color = fragColor;
}