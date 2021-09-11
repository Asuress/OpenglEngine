#pragma once

#include <glm/glm.hpp>

class Vertex
{
private:
    glm::vec3 position;
public:
    Vertex(const glm::vec3& pos);
    ~Vertex();
    void move(glm::vec3& direction);
    glm::vec3* getPosition();
};
