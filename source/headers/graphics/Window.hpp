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
    GLFWkeyfun keyInputFun;
    void keyInputCallback(GLFWwindow*, int, int, int, int);
public:
    Window(int width, int height, std::string title);
    ~Window();
    GLFWwindow* getGLFWwindow();
    void swapBuffers();
    void pollEvents();
    void clear(float, float, float, float);
};

