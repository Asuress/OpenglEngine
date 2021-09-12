//---------------------include default libs------------------------------------
#include <iostream>
#include <vector>
//---------------------include custom files------------------------------------
#include "main/Vertex.hpp"
//---------------------include OGL libs----------------------------------------
#include <GL/glew.h>
#include "main/Utils.hpp"

class Mesh
{
private:
    float* vertices;
    GLuint vao[1];
    GLuint vbo[2];
public:
    void setVertices(std::vector<Vertex> newVertices);
    void draw();
    Mesh(float* vertices, int numVertices, GLenum mode = GL_STATIC_DRAW);
    Mesh();
    ~Mesh();
};
