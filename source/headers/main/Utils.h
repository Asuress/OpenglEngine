#ifndef UTILS_H
#define UTILS_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL2/SOIL2.h>
#include <iostream>
#include <fstream>
#include <string>

class Utils {
public:
	static GLuint createShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource);
	static GLuint createShaderProgram(const char* vp, const char* gp, const char* fp);
	static GLuint createShaderProgram(const char* vp, const char* tCS, const char* tES, const char* fp);
	static GLuint createShaderProgram(const char* vp, const char* tCS, const char* tES, const char* gp, const char* fp);
	static std::string readShaderSource(const char* filePath);
	static GLuint loadTexture(const char* path);
	static void printShaderLog(GLuint shader);
	static void printProgramLog(int prog);
	static bool checkOpenGLError();
	static float* goldAmbient();
	static float* goldDiffuse();
	static float* goldSpecular();
	static float goldShininess();

	static float* silverAmbient();
	static float* silverDiffuse();
	static float* silverSpecular();
	static float silverShininess();

	static float* bronzeAmbient();
	static float* bronzeDiffuse();
	static float* bronzeSpecular();
	static float bronzeShininess();
};
#endif
