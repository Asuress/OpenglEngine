#pragma once

#include <GL/glew.h>
#include <string>
#include <fstream>
#include <sstream>
#include "main/Utils.hpp"

class ShaderProgram
{
private:
    GLuint vertexShader;
    GLuint geometryShader;
    GLuint fragmentShader;
    GLuint tessellationShader;
    GLuint glProgram;
public:
    ShaderProgram(std::string& vShaderSource, std::string& gShaderSource, std::string& fShaderSource);
    ShaderProgram();
    ~ShaderProgram();

    void bind();
    void loadShader(std::string shaderSource, GLenum type);
    GLuint getProgram();
    static std::string readShaderSource(std::string filePath);
};
