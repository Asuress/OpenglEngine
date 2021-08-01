#include "graphics/Window.hpp"

GLFWwindow* Window::getGLFWwindow()
{
    return gl_window;
}

void Window::swapBuffers() {
    glfwSwapBuffers(gl_window);
    glfwPollEvents();
}

void Window::clear(float red, float green, float blue, float alpha) {
    glClearColor(red, green, blue, alpha);
    glClear(GL_COLOR_BUFFER_BIT);
}