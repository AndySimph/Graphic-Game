#version 130
//Fragment shader operates on each pixel in a given polygon

//3 Component float vector that gets outputted to the screen for each pixel
out vec3 color;

void main() {
    color = vec3(1.0, 0.0, 1.0);
}