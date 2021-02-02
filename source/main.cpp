//--------------------------------------Including opengl libs-------------------------------------------
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
//--------------------------------------Including default libraries-------------------------------------
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <stack>
//--------------------------------------Including custom files------------------------------------------
#include "graphics/headers/Utils.h"

using namespace std;

#define numVAOs 1 
#define numVBOs 2
float cameraX, cameraY, cameraZ;
float cubeLocX, cubeLocY, cubeLocZ;
float pyramidLocX, pyramidLocY, pyramidLocZ;
GLuint renderingProgram;
GLuint vao[numVAOs];
GLuint vbo[numVBOs];

// allocate variables used in display() function, so that they won�t need to be allocated during rendering 

GLuint vLoc, projLoc, mLoc, mvLoc;
int width, height; 
float aspect;
glm::mat4 pMat, vMat, mMat, mvMat;

void setupVertices(void) {
	// 36 vertices, 12 triangles, makes 2x2x2 cube placed at origin
	float cubePositions[108] = { -1.0f, 1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 1.0f, -1.0f, -1.0f,
								1.0f, -1.0f, -1.0f, 1.0f, 1.0f, -1.0f, -1.0f, 1.0f, -1.0f,
								1.0f, -1.0f, -1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 1.0f, -1.0f,
								1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, -1.0f,
								1.0f, -1.0f, 1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
								-1.0f, -1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
								-1.0f, -1.0f, 1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 1.0f, 1.0f,
								-1.0f, -1.0f, -1.0f, -1.0f, 1.0f, -1.0f, -1.0f, 1.0f, 1.0f,
								-1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, -1.0f,
								1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 1.0f,
								-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 1.0f,
								1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, -1.0f
	};

	// pyramid with 18 vertices, comprising 6 triangles (four sides, and two on the bottom)
	float pyramidPositions[54] = {
		-1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 0.0f,	// front face
		1.0f, -1.0f, 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 1.0f, 0.0f,	// right face
		1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 0.0f, 1.0f, 0.0f,	// back face
		-1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 0.0f,	// left face
		-1.0f, -1.0f, -1.0f, 1.0f, -1.0f, 1.0f, -1.0f, -1.0f, 1.0f,	// base – left front
		1.0f, -1.0f, 1.0f, -1.0f, -1.0f, -1.0f, 1.0f, -1.0f, -1.0f	// base – right back
	};
	glGenVertexArrays(numVAOs, vao);
	glBindVertexArray(vao[0]);
	glGenBuffers(numVBOs, vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cubePositions), cubePositions, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(pyramidPositions), pyramidPositions, GL_STATIC_DRAW);
}

void init(GLFWwindow* window) {
	string vShaderSource = Utils::readShaderSource("C:\\Users\\Admin\\source\\repos\\Engine\\OpenglEngine\\source\\graphics\\shaders\\vertShader.glsl");
	string fShaderSource = Utils::readShaderSource("C:\\Users\\Admin\\source\\repos\\Engine\\OpenglEngine\\source\\graphics\\shaders\\fragShader.glsl");

	renderingProgram = Utils::createShaderProgram(vShaderSource.c_str(), fShaderSource.c_str());


	//CHECK FOR ERRORS
	Utils::checkOpenGLError();
	Utils::printProgramLog(renderingProgram);

	GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
	// GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
	auto shaderSource = vShaderSource.c_str();

	glShaderSource(vShader, 1, &shaderSource, NULL);

	glCompileShader(vShader);

	Utils::checkOpenGLError();
	Utils::printShaderLog(vShader);
	//CHECH ENDED

	cameraX = 0.0f;
	cameraY = 0.0f;
	cameraZ = 16.0f;

	cubeLocX = 0.0f;
	cubeLocY = -2.0f;
	cubeLocZ = 5.0f;

	pyramidLocX = 1.0f;
	pyramidLocY = 0.0f;
	pyramidLocZ = -1.0f;

	setupVertices();
	
	glfwGetFramebufferSize(window, &width, &height);
	aspect = (float)width / (float)height;
	pMat = glm::perspective(1.0472f, aspect, 0.1f, 1000.0f); // 1.0472 radians = 60 degrees
}

// stack<glm::mat4> mvStack;
stack<glm::mat4> mvStack;

void display(GLFWwindow* window, double currentTime) {
	glClear(GL_DEPTH_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(renderingProgram);

	// get the uniform variables for the MV and projection matrices
	// mLoc = glGetUniformLocation(renderingProgram, "m_matrix");
	// vLoc = glGetUniformLocation(renderingProgram, "v_matrix");
	projLoc = glGetUniformLocation(renderingProgram, "proj_matrix");
	mvLoc = glGetUniformLocation(renderingProgram, "mv_matrix");

	// build view matrix
	vMat = glm::translate(glm::mat4(1.0f), glm::vec3(-cameraX, -cameraY, -cameraZ));
	mvStack.push(vMat);

	// ---------------------- pyramid == sun -------------------------------------------
	mvStack.push(mvStack.top());
	mvStack.top() *= glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f)); // sun position
	mvStack.push(mvStack.top());
	mvStack.top() *= glm::rotate(glm::mat4(1.0f), (float)currentTime, glm::vec3(1.0f, 0.0f, 0.0f)); // sun rotation
	
	glUniformMatrix4fv(mvLoc, 1, GL_FALSE, glm::value_ptr(mvStack.top()));
	
	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LEQUAL);
	glDrawArrays(GL_TRIANGLES, 0, 18);
	mvStack.pop();
	
	//----------------------------------set up planet-------------------------
	mvStack.push(mvStack.top());
	mvStack.top() *= glm::translate(glm::mat4(1.0f), glm::vec3(sin((float)currentTime)*4.0, 0.0f, cos((float)currentTime)*4.0));
	mvStack.push(mvStack.top());
	mvStack.top() *= glm::rotate(glm::mat4(1.0f), (float)currentTime, glm::vec3(0.0, 1.0, 0.0)); // planet rotation
	
	glUniformMatrix4fv(mvLoc, 1, GL_FALSE, glm::value_ptr(mvStack.top()));
	
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	mvStack.pop();

	//----------------------- smaller cube == moon ----------------------------------
	mvStack.push(mvStack.top());
	mvStack.top() *= glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, sin((float)currentTime) * 2.0, cos((float)currentTime) * 2.0)); // moon rotation
	mvStack.top() *= glm::rotate(glm::mat4(1.0f), (float)currentTime, glm::vec3(0.0, 0.0, 1.0));
	mvStack.top() *= glm::scale(glm::mat4(1.0f), glm::vec3(0.25f, 0.25f, 0.25f)); // make the moon smaller
	
	glUniformMatrix4fv(mvLoc, 1, GL_FALSE, glm::value_ptr(mvStack.top()));
	
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	glDrawArrays(GL_TRIANGLES, 0, 36); // draw the moon
	
	// remove moon scale/rotation/position, planet position, sun position, and view matrices from stack
	mvStack.pop(); mvStack.pop(); mvStack.pop(); mvStack.pop();
	
	// //Draw the cube

	// mMat = glm::translate(glm::mat4(1.0f), glm::vec3(cubeLocX, cubeLocY, cubeLocZ));
	// //mvMat = vMat * mMat;

	// float timeFactor = float(currentTime);
	// GLuint timeFactorLocation = glGetUniformLocation(renderingProgram, "time_factor");
	// glUniform1f(timeFactorLocation, timeFactor);
	
	// glUniformMatrix4fv(mLoc, 1, GL_FALSE, glm::value_ptr(mMat));
	// glUniformMatrix4fv(vLoc, 1, GL_FALSE, glm::value_ptr(vMat));
	// glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(pMat));
	
	// // associate VBO with the corresponding vertex attribute in the vertex shader
	
	// glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	// glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); 
	// glEnableVertexAttribArray(0);
	// // adjust OpenGL settings and draw model 
	// glEnable(GL_DEPTH_TEST); 
	// glDepthFunc(GL_LEQUAL); 
	// glDrawArrays(GL_TRIANGLES, 0, 36);

	// //Draw the pyramid
	// mMat = glm::translate(glm::mat4(1.0f), glm::vec3(pyramidLocX, pyramidLocY, pyramidLocZ));

	// glUniformMatrix4fv(mLoc, 1, GL_FALSE, glm::value_ptr(mMat));
	// glUniformMatrix4fv(vLoc, 1, GL_FALSE, glm::value_ptr(vMat));
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(pMat));

	// glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	// glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	// glEnableVertexAttribArray(0);

	// glEnable(GL_DEPTH_TEST);
	// glDepthFunc(GL_LEQUAL);
	// glDrawArrays(GL_TRIANGLES, 0, 18);
}

void window_reshape_callback(GLFWwindow* window, int newWidth, int newHeight){
	aspect = (float)newWidth / (float)newHeight;
	glViewport(0, 0, newWidth, newHeight);
	pMat = glm::perspective(1.0472f, aspect, 0.1f, 1000.0f); // 1.0472 radians = 60 degrees
}

void window_scroll_callback(GLFWwindow *window, double x, double y){
	// cameraX -= x;
	cameraZ -= y;
}

int main(void) {
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	GLFWwindow* window = glfwCreateWindow(600, 600, "Chapter 4 - program 1", NULL, NULL);
	glfwMakeContextCurrent(window);
    
	if (glewInit() != GLEW_OK) {
		exit(EXIT_FAILURE);
	}
	glfwSwapInterval(1);
	
	glfwSetWindowSizeCallback(window, window_reshape_callback);

	glfwSetScrollCallback(window, window_scroll_callback);

	init(window);
	while (!glfwWindowShouldClose(window)) {
		display(window, glfwGetTime());
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
