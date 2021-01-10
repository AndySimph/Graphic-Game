#version 130
//Fragment shader operates on each pixel in a given polygon

//Take in given vector colors and positions
in vec2 fragPos;
in vec4 fragColor;

//3 Component float vector that gets outputted to the screen for each pixel
out vec4 color;

//Uniform variable that reacts over time
uniform float time;

void main() {
    // color = fragColor + vec4(1.0 * (cos(time) + 1.0) * 0.5, 
    //                     1.0 * (cos(time + 2) + 1.0) * 0.5,
    //                     1.0 * (sin(time + 1) + 1.0) * 0.5,
    //                     0.0);

    // color = vec4(fragColor.r * (cos(fragPos.x + time) + 1.0) * 0.5, 
    //             fragColor.g * (cos(fragPos.y + time) + 1.0) * 0.5, 
    //             fragColor.b * (cos(fragPos.x * 0.4 + time) + 1.0) * 0.5, 
    //             fragColor.a);

    color = vec4(fragColor.r * (cos(fragPos.x * 4 + time) + 1.0) * 0.5, 
                fragColor.g * (cos(fragPos.y * 8 + time) + 1.0) * 0.5, 
                fragColor.b * (cos(fragPos.x * 2 + time) + 1.0) * 0.5, 
                fragColor.a);

    return;
}