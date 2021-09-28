#include "graphics/Mesh.hpp"

Mesh::Mesh(float* vertices, int numVertices, GLenum mode)
{
    this->vertices = std::make_unique<float>();
    this->vertices.reset(vertices);

    glGenVertexArrays(1, vao);
    glGenBuffers(2, vbo);

    glBindVertexArray(vao[0]);
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(*vertices) * numVertices, vertices, mode);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    if (Utils::checkOpenGLError()) {
        std::cout << "Mesh creation error" << std::endl;
    }
}

Mesh::Mesh()
{

}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, vao);
    glDeleteBuffers(2, vbo);
}


void Mesh::setVertices(float* newVertices)
{
    // vertices = newVertices;
}

float* Mesh::getVertices()
{
    return vertices.get();
}

void Mesh::draw(GLenum mode, GLuint verticesCount)
{
    glBindVertexArray(vao[0]);
    glDrawArrays(mode, 0, verticesCount);
}