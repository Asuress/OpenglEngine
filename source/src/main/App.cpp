#include "main/App.h"

App* App::instance = nullptr;

App::App() {
    isInitialized = false;
}

App::~App() {
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

void App::start() {
    mainLoop();
}

bool App::init() {
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
        return false;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    window = glfwCreateWindow(800, 600, appName.c_str(), NULL, NULL);
    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK) {
        exit(EXIT_FAILURE);
        return false;
    }
    glfwSwapInterval(1);

    isInitialized = true;
    return isInitialized;
}

App* App::getApp() {
    if (App::instance == nullptr) {
        App::instance = new App();
    }
    return App::instance;
}

void App::setName(const char* appName) {
    this->appName = appName;
}

const char* App::getAppName() {
    return appName.c_str();
}

void App::mainLoop() {
    while (!glfwWindowShouldClose(window)) {
        fixedUpdate();
        earlyUpdate();
        update();
        lateUpdate();
        render();
    }
}

void App::collisionCheck() {
    auto it = scene.getObjectsIteratorBegin();
    while (it != scene.getObjectsIteratorEnd()) {
        it->collisionCheck();
        it++;
    }
}

void App::fixedUpdate() {
    auto it = scene.getObjectsIteratorBegin();
    while (it != scene.getObjectsIteratorEnd()) {
        it->fixedUpdate();
        it++;
    }
}

void App::earlyUpdate() {
    auto it = scene.getObjectsIteratorBegin();
    while (it != scene.getObjectsIteratorEnd()) {
        it->earlyUpdate();
        it++;
    }
}

void App::update() {
    auto it = scene.getObjectsIteratorBegin();
    while (it != scene.getObjectsIteratorEnd()) {
        it->update();
        it++;
    }
}

void App::lateUpdate() {
    auto it = scene.getObjectsIteratorBegin();
    while (it != scene.getObjectsIteratorEnd()) {
        it->lateUpdate();
        it++;
    }
}

void App::render() {
    auto it = scene.getObjectsIteratorBegin();
    while (it != scene.getObjectsIteratorEnd()) {
        it->display();
        it++;
    }
    glfwSwapBuffers(window);
    glfwPollEvents();
}
