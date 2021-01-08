//Header file for the GLSLProgram class

//Libraries
#include <string>
#include <GL/glew.h>
#include "error.h"

#pragma once

class GLSLProgram {
    public:
        //Constructor and Destructor
        GLSLProgram();
        ~GLSLProgram();

        //Functions to compile, link, and add attributes to the shader
        void compileShaders(const std::string& vertShaderpath, const std::string& fragShaderpath);
        void linkShaders();
        void addAttribute(const std::string& attrName);

        //function to enable and disable shaders
        void enable();
        void disable();

    private:
        GLuint _progID;
        GLuint _vertShaderID;
        GLuint _fragShaderID;
        int _numAttributes;

        //Function to compile shaders
        void compileShader(const std::string& filePath, GLuint& id);
};
