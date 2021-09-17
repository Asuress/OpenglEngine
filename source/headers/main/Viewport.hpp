#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace viewport {

    class Viewport
    {
    private:
        glm::vec2 position;
        int width;
        int height;
    public:
        Viewport(int x, int y, int width, int height);
        ~Viewport();

        void setPosition(glm::vec2 newPos);
        void setBoundaries(int newWidth, int newHeight);
        void useViewport();
    };

}