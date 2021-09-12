#include "main/Vertex.hpp"

Vertex::Vertex(const glm::vec3& pos)
{
    position = pos;
}

Vertex::~Vertex()
{

}

void Vertex::move(glm::vec3& direction)
{
    position += direction;
}