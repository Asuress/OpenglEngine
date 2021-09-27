#include "graphics/Window.hpp"

Window::Window(int width, int height, std::string title)
{
    if (!glfwInit())
    {
        exit(EXIT_FAILURE);
        std::cout << "GLFW is not ok" << std::endl;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    gl_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    glfwMakeContextCurrent(gl_window);
    (*this).keyInputCallback(gl_window, 0, 0, 0, 0);
    glfwSetKeyCallback(gl_window, keyInputFun);
    if (glewInit() != GLEW_OK)
    {
        exit(EXIT_FAILURE);
        std::cout << "GLEW is not ok" << std::endl;
    }
    glfwSwapInterval(1);
}

Window::~Window()
{
    glfwMakeContextCurrent(NULL);
    glfwDestroyWindow(gl_window);
}

GLFWwindow* Window::getGLFWwindow()
{
    return gl_window;
}

void Window::swapBuffers()
{
    glfwSwapBuffers(gl_window);
}

void Window::pollEvents()
{
    glfwPollEvents();
}

void Window::clear(float red, float green, float blue, float alpha)
{
    glClearColor(red, green, blue, alpha);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::keyInputCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{

}