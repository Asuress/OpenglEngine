#pragma once
//---------------------include default libs------------------------------------
#include <iostream>
#include <vector>
//---------------------include custom files------------------------------------
#include "main/Vertex.hpp"
//---------------------include OGL libs----------------------------------------
#include <GL/glew.h>
// #include <GLFW/glfw3.h>
#include "main/Utils.hpp"
#include <memory>

class Mesh
{
private:
    std::unique_ptr<float> vertices;
    GLuint vao[1];
    GLuint vbo[2];
public:
    void setVertices(float* newVertices);
    float* getVertices();
    void draw(GLenum mode = GL_TRIANGLES, GLuint verticesCount = 3);
    Mesh(float* vertices, int numVertices, GLenum mode = GL_STATIC_DRAW);
    Mesh();
    ~Mesh();
};
