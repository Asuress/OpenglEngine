#include "graphics/renderable/UI/Button.hpp"

Button::Button(float width, float height, glm::vec3 position) : pos(position), width(width), height(height)
{
    float vertices[] = {
        pos.x, pos.y, pos.z,
        pos.x + width, pos.y, pos.z,
        pos.x, pos.y + height, pos.z,
        pos.x + width, pos.y + height, pos.z
    };
    shader = std::make_unique<ShaderProgram>();

    std::string vShaderSrc = shader->readShaderSource("../source/src/graphics/shaders/buttonVert.glsl");
    shader->loadShader(vShaderSrc, GL_VERTEX_SHADER);

    std::string fShaderSrc = shader->readShaderSource("../source/src/graphics/shaders/buttonFrag.glsl");
    shader->loadShader(fShaderSrc, GL_FRAGMENT_SHADER);

    mesh = std::make_unique<Mesh>(vertices, sizeof(vertices) / sizeof(float));
}

Button::~Button()
{

}

void Button::display()
{
    shader->linkProgram();
    shader->useProgram();
    mesh->draw(GL_TRIANGLE_STRIP, 4);
}