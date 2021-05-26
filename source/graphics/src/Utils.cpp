#include "main/Utils.h"

GLuint Utils::createShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource) {
	GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vShader, 1, &vertexShaderSource, NULL);
	glShaderSource(fShader, 1, &fragmentShaderSource, NULL);

	glCompileShader(vShader);
	glCompileShader(fShader);

	GLuint program = glCreateProgram();

	glAttachShader(program, vShader);
	glAttachShader(program, fShader);

	glLinkProgram(program);

	return program;
}

GLuint Utils::createShaderProgram(const char* vp, const char* gp, const char* fp) {
	return GLuint();
}

GLuint Utils::createShaderProgram(const char* vp, const char* tCS, const char* tES, const char* fp) {
	return GLuint();
}

GLuint Utils::createShaderProgram(const char* vp, const char* tCS, const char* tES, const char* gp, const char* fp) {
	return GLuint();
}

GLuint Utils::loadTexture(const char* path) {
	GLuint textureID;
	textureID = SOIL_load_OGL_texture(path, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	if (textureID == 0)
		std::cout << "could not find texture file " << path << std::endl;
	return textureID;
}

std::string Utils::readShaderSource(const char* filePath) {
	std::string content;
	std::ifstream ifstr(filePath, std::ios::in);
	std::string line = "";
	if (ifstr.is_open()) {
		while (!ifstr.eof()) {
			getline(ifstr, line);
			content.append(line + "\n");
		}
		ifstr.close();
	}
	return content;
}

void Utils::printShaderLog(GLuint shader) {
	int len = 0;
	int chWrittn = 0;
	char* log;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
	if (len > 0) {
		log = (char*)malloc(len);
		glGetShaderInfoLog(shader, len, &chWrittn, log);
		std::cout << "Shader Info Log: " << log << std::endl;
		free(log);
	}
}

void Utils::printProgramLog(int prog) {
	int len = 0;
	int chWrittn = 0;
	char* log;
	glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &len);
	if (len > 0) {
		log = (char*)malloc(len);
		glGetProgramInfoLog(prog, len, &chWrittn, log);
		std::cout << "Program Info Log: " << log << std::endl;
		free(log);
	}
}

bool Utils::checkOpenGLError() {
	bool foundError = false;
	int glErr = glGetError();
	while (glErr != GL_NO_ERROR) {
		std::cout << "glError: " << glErr << std::endl;
		foundError = true;
		glErr = glGetError();
	}
	return foundError;
}

// GOLD material
float* Utils::goldAmbient() {
	static float a[4] = { 0.2473f, 0.1995f, 0.0745f, 1 };
	return (float*)a;
}
float* Utils::goldDiffuse() {
	static float a[4] = { 0.7516f, 0.6065f, 0.2265f, 1 };
	return (float*)a;
}
float* Utils::goldSpecular() {
	static float a[4] = { 0.6283f, 0.5559f, 0.3661f, 1 };
	return (float*)a;
}
float Utils::goldShininess() {
	return 51.2f;
}

// SILVER material - ambient, diffuse, specular, and shininess
float* Utils::silverAmbient() { static float a[4] = { 0.1923f, 0.1923f, 0.1923f, 1 }; return (float*)a; }
float* Utils::silverDiffuse() { static float a[4] = { 0.5075f, 0.5075f, 0.5075f, 1 }; return (float*)a; }
float* Utils::silverSpecular() { static float a[4] = { 0.5083f, 0.5083f, 0.5083f, 1 }; return (float*)a; }
float Utils::silverShininess() { return 51.2f; }

//Bronze material
float* Utils::bronzeAmbient() { static float a[4] = { 0.2125f, 0.1275f, 0.0540f, 1 }; return (float*)a; }
float* Utils::bronzeDiffuse() { static float a[4] = { 0.7140f, 0.4284f, 0.1814f, 1 }; return (float*)a; }
float* Utils::bronzeSpecular() { static float a[4] = { 0.3936f, 0.2719f, 0.1667f, 1 }; return (float*)a; }
float Utils::bronzeShininess() { return 25.6f; }