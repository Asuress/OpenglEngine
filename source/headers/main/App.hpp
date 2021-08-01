#ifndef APP_H
#define APP_H

#include <string>
#include <vector>
#include <list>
// ---------------------------------------OGL Libs----------------------------------
#include <GL/glew.h>
#include <GLFW/glfw3.h>
// ---------------------------------------Custom Headers----------------------------
#include "main/GameObject.hpp"
#include "main/Scene.hpp"

class App
{
public:
    static App* getApp();
    const char* getAppName();
    void setName(const char*);
    bool init();
    void start();

private:
    App();
    ~App();
    bool isInitialized;
    static App* instance;
    std::string appName;
    Scene scene;
    GLFWwindow* window;
    void mainLoop();
    void collisionCheck();
    void fixedUpdate();
    void earlyUpdate();
    void update();
    void lateUpdate();
    void render();
};

#endif
