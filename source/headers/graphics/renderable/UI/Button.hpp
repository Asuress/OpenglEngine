#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "graphics/renderable/IRenderable.hpp"
#include "glm/glm.hpp"
#include "graphics/Mesh.hpp"
#include "graphics/ShaderProgram.hpp"
#include "main/Utils.hpp"
#include <memory>

class Button : public IRenderable
{
private:
    glm::vec3 pos;
    std::unique_ptr<ShaderProgram> shader;
    float width;
    float height;
    std::unique_ptr<Mesh> mesh;

public:
    Button(float width, float height, glm::vec3 position);
    ~Button();

    void display() override;
};
