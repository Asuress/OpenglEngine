//--------------------------------------Including opengl libs-------------------------------------------
// #include <GL/glew.h>
// #include <GLFW/glfw3.h>
// #include <glm/glm.hpp>
// #include <glm/gtc/type_ptr.hpp>
// #include <glm/gtc/matrix_transform.hpp>
//--------------------------------------Including default libs------------------------------------------
// #include <string>
#include <iostream>
// #include <fstream>
// #include <cmath>
// #include <stack>
//--------------------------------------Including custom files------------------------------------------
// #include "main/Utils.h"
// #include "main/Renderable/Shapes/Sphere.h"
#include "main/App.hpp"
#include "graphics/Window.hpp"
#include "graphics/ShaderProgram.hpp"

int main(void)
{
	Window window = Window(800, 600, "Title");
	int i = 0;
	std::string str = ShaderProgram::readShaderSource("../source/src/graphics/shaders/fragShader.frag");
	// std::cout << str << std::endl;
	ShaderProgram* shader = new ShaderProgram(str, str, str);
	while (!glfwWindowShouldClose(window.getGLFWwindow()))
	{
		window.clear(0.0, 0.15, 0.001 * i, 1.0);
		shader->useProgram();
		window.swapBuffers();
		i++;
		glfwPollEvents();
	}

	glfwTerminate();
	exit(EXIT_SUCCESS);

	// App* app = App::getApp();
	// app->setName("App Name");
	// if (!app->init())
	// {
	// 	return -1;
	// }
	// app->start();
	// return 0;
}
