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

int main(void)
{
	App* app = App::getApp();
	if (!app->init())
	{
		return -1;
	}
	app->setName("App Name");
	app->start();
	std::cout << "Hey" << std::endl;
	return 0;
}
