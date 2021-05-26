#include "main/Scene.h"

Scene::Scene() {

}

Scene::~Scene() {

}

std::list<Object>::iterator Scene::getObjectsIteratorBegin() {
    return objects.begin();
}

std::list<Object>::iterator Scene::getObjectsIteratorEnd() {
    return objects.end();
}

void Scene::addObject(Object& obj) {
    objects.push_back(obj);
}

void Scene::loadScene() {
    
}
