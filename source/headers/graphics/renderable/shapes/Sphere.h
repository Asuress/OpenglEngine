#pragma once
#include <cmath>
#include <vector>
#include <glm/glm.hpp>
#include "graphics/renderable/IRenderable.h"
#include "graphics/renderable/shapes/Shape.h"

class Sphere : public IRenderable, public Shape {
private:
    int numVertices;
    int numIndices;
    std::vector<int> indices;
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec2> texCoords;
    void init(int);
    float toRadians(float degrees);

public:
    Sphere(int prec);
    Sphere();
    int getNumVertices();
    int getNumIndices();
    std::vector<int> getIndices();
    std::vector<glm::vec3> getVertices();
    std::vector<glm::vec3> getNormals();
    std::vector<glm::vec2> getTexCoords();
    void display() override;
    ~Sphere() {};
};
