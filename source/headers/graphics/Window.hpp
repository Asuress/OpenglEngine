#pragma once

#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

class Window
{
private:
    int width;
    int height;
    std::string title;
    GLFWwindow* gl_window;
public:
    Window(int width, int height, std::string title);
    ~Window();
    GLFWwindow* getGLFWwindow();
    void swapBuffers();
    void clear(float, float, float, float);
};

inline Window::Window(int width, int height, std::string title)
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
    if (glewInit() != GLEW_OK)
    {
        exit(EXIT_FAILURE);
        std::cout << "GLEW is not ok" << std::endl;
    }
    glfwSwapInterval(1);
}

inline Window::~Window()
{
    glfwDestroyWindow(gl_window);
}
