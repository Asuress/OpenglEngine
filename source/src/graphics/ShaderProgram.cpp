#include "graphics/ShaderProgram.hpp"

ShaderProgram::ShaderProgram(std::string& vShaderSource, std::string& gShaderSource, std::string& fShaderSource)
{
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    geometryShader = glCreateShader(GL_GEOMETRY_SHADER);
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    const char* vText = vShaderSource.c_str();
    const char* gText = gShaderSource.c_str();
    const char* fText = fShaderSource.c_str();
    glShaderSource(vertexShader, 1, &vText, NULL);
    glShaderSource(geometryShader, 1, &gText, NULL);
    glShaderSource(fragmentShader, 1, &fText, NULL);

    if (Utils::checkOpenGLError()) {
        Utils::printShaderLog(vertexShader);
        Utils::printShaderLog(geometryShader);
        Utils::printShaderLog(fragmentShader);
    }

    glCompileShader(vertexShader);
    glCompileShader(geometryShader);
    glCompileShader(fragmentShader);

    if (Utils::checkOpenGLError()) {
        Utils::printShaderLog(vertexShader);
        Utils::printShaderLog(geometryShader);
        Utils::printShaderLog(fragmentShader);
    }

    glProgram = glCreateProgram();

    glAttachShader(glProgram, vertexShader);
    glAttachShader(glProgram, geometryShader);
    glAttachShader(glProgram, fragmentShader);

    if (Utils::checkOpenGLError()) {
        Utils::printProgramLog(glProgram);
    }

    glLinkProgram(glProgram);

    if (Utils::checkOpenGLError()) {
        Utils::printProgramLog(glProgram);
    }
}

ShaderProgram::ShaderProgram()
{
    glProgram = glCreateProgram();
    if (Utils::checkOpenGLError()) {
        Utils::printProgramLog(glProgram);
    }
}

ShaderProgram::~ShaderProgram()
{
    glDetachShader(glProgram, vertexShader);
    glDeleteShader(vertexShader);
    glDetachShader(glProgram, geometryShader);
    glDeleteShader(geometryShader);
    glDetachShader(glProgram, fragmentShader);
    glDeleteShader(fragmentShader);
    glDetachShader(glProgram, tessellationShader);
    glDeleteShader(tessellationShader);
    glDeleteProgram(glProgram);
}

void ShaderProgram::loadShader(std::string& shaderSource, GLenum shaderType)
{
    const char* src = shaderSource.c_str();
    switch (shaderType)
    {
    case GL_VERTEX_SHADER:
        vertexShader = glCreateShader(shaderType);
        glShaderSource(vertexShader, 1, &src, NULL);
        glCompileShader(vertexShader);
        glAttachShader(glProgram, vertexShader);
        break;
    case GL_GEOMETRY_SHADER:
        geometryShader = glCreateShader(shaderType);
        glShaderSource(geometryShader, 1, &src, NULL);
        glCompileShader(geometryShader);
        glAttachShader(glProgram, geometryShader);
        break;
    case GL_FRAGMENT_SHADER:
        fragmentShader = glCreateShader(shaderType);
        glShaderSource(fragmentShader, 1, &src, NULL);
        glCompileShader(fragmentShader);
        glAttachShader(glProgram, fragmentShader);
        break;

    default:
        break;
    }
    if (Utils::checkOpenGLError()) {
        Utils::printProgramLog(glProgram);
    }
    if (Utils::checkOpenGLError()) {
        Utils::printShaderLog(vertexShader);
        Utils::printShaderLog(geometryShader);
        Utils::printShaderLog(fragmentShader);
    }
}

void ShaderProgram::linkProgram()
{
    glLinkProgram(glProgram);
    if (Utils::checkOpenGLError()) {
        Utils::printProgramLog(glProgram);
    }
}

void ShaderProgram::useProgram()
{
    glUseProgram(glProgram);
    if (Utils::checkOpenGLError()) {
        Utils::printProgramLog(glProgram);
    }
}

GLuint ShaderProgram::getProgram()
{
    return glProgram;
}

std::string ShaderProgram::readShaderSource(std::string filePath)
{
    std::ifstream ifstr;
    std::stringstream output;
    std::string line;
    ifstr.open(filePath);
    if (ifstr.is_open())
        output << ifstr.rdbuf();
    ifstr.close();
    return output.str();
}