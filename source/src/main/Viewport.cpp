#include "./main/Viewport.hpp"

using namespace viewport;

void Viewport::setPosition(glm::vec2 newPos)
{
    glViewport(newPos.x, newPos.y, width, height);
}

void Viewport::setBoundaries(int newWidth, int newHeight)
{
    glViewport(position.x, position.y, newWidth, newHeight);
}

void Viewport::useViewport()
{
    glViewport(position.x, position.y, width, height);
}

Viewport::Viewport(int x, int y, int width, int height)
{
    position = glm::vec2(x, y);
    this->width = width;
    this->height = height;
}