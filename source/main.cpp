//--------------------------------------Including default libs------------------------------------------
#include <iostream>
//--------------------------------------Including custom files------------------------------------------
#include "main/App.hpp"
#include "graphics/Window.hpp"
#include "graphics/ShaderProgram.hpp"
#include "main/Vertex.hpp"
#include "graphics/Mesh.hpp"
#include "graphics/renderable/UI/Button.hpp"

int main(void)
{
	Window window = Window(800, 600, "Title");
	std::string fSrc = ShaderProgram::readShaderSource("../source/src/graphics/shaders/fragShader.frag");
	std::string vSrc = ShaderProgram::readShaderSource("../source/src/graphics/shaders/vertShader.vert");
	ShaderProgram* shader = new ShaderProgram();
	shader->loadShader(fSrc, GL_FRAGMENT_SHADER);
	shader->loadShader(vSrc, GL_VERTEX_SHADER);
	shader->linkProgram();

	float vertices[] = {
		-0.5f, -0.5f, 0.0f,	// левая вершина
		0.5f, -0.5f, 0.0f,	// правая вершина
		0.0f, 0.5f, 0.0f,	// верхняя вершина
	};
	// flip by X and Y axis
	float vertices2[] = {
		0.0f, 0.5f, 0.0f,	// upper left
		1.0f, 0.5f, 0.0f,	// upper right
		0.5f, -0.5f, 0.0f	// lower
	};

	Mesh* mesh = new Mesh(vertices, sizeof(vertices) / sizeof(float));
	Mesh* mesh2 = new Mesh(vertices2, sizeof(vertices2) / sizeof(float));

	Button button = Button(2, 1, glm::vec3(0, 0, 0));

	while (!glfwWindowShouldClose(window.getGLFWwindow()))
	{
		window.clear(0.0, 0.0, 0.0, 1.0);

		shader->linkProgram();
		shader->useProgram();
		mesh->draw();
		mesh2->draw();

		button.display();

		window.swapBuffers();
		window.pollEvents();
	}

	glfwTerminate();
	exit(EXIT_SUCCESS);
}
