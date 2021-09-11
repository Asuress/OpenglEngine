//--------------------------------------Including default libs------------------------------------------
#include <iostream>
//--------------------------------------Including custom files------------------------------------------
#include "main/App.hpp"
#include "graphics/Window.hpp"
#include "graphics/ShaderProgram.hpp"
#include "main/Vertex.hpp"
#include "graphics/Mesh.hpp"

GLuint vao[1];
GLuint vbo[2];

void display()
{

}

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
		// flip by X and Y axis
		0.0f, 0.5f, 0.0f,	// upper left
		0.5f, 1.0f, 0.0f,	// upper right
		0.5f, -0.5f, 0.0f	// lower
	};

	std::cout << sizeof(vertices) << std::endl;

	Mesh* mesh = new Mesh(vertices, sizeof(vertices) / sizeof(float));

	while (!glfwWindowShouldClose(window.getGLFWwindow()))
	{
		window.clear(0.0, 0.0, 0.0, 1.0);
		// glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		// glClear(GL_COLOR_BUFFER_BIT);
		shader->useProgram();
		mesh->draw();
		// glBindVertexArray(vao[0]);
		// glDrawArrays(GL_TRIANGLES, 0, 3);

		window.swapBuffers();
	}

	glfwTerminate();
	exit(EXIT_SUCCESS);
}
