#ifndef SCENE_H
#define SCENE_H

#include <list>
#include "main/Object.h"

class Scene {
private:
    std::list<Object> objects;
public:
    Scene();
    ~Scene();
    void loadScene();
    void addObject(Object& obj);
    std::list<Object>::iterator getObjectsIteratorBegin();
    std::list<Object>::iterator getObjectsIteratorEnd();
};
#endif
