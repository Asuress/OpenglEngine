#include "main/Scene.hpp"

Scene::Scene() {}

Scene::~Scene() {}

std::list<GameObject>::iterator Scene::getObjectsIteratorBegin() {
    return objects.begin();
}

std::list<GameObject>::iterator Scene::getObjectsIteratorEnd() {
    return objects.end();
}

void Scene::addObject(GameObject& obj) {
    objects.push_back(obj);
}

void Scene::loadScene() {}

void Scene::callFrame() {
    auto it = objects.begin();
    while (it != objects.end()) {
        it->collisionCheck();
        it++;
    }

    it = objects.begin();
    while (it != objects.end()) {
        it->fixedUpdate();
        it++;
    }

    it = objects.begin();
    while (it != objects.end()) {
        it->earlyUpdate();
        it++;
    }

    it = objects.begin();
    while (it != objects.end()) {
        it->update();
        it++;
    }

    it = objects.begin();
    while (it != objects.end()) {
        it->lateUpdate();
        it++;
    }

    it = objects.begin();
    while (it != objects.end()) {
        it->display();
        it++;
    }
}
