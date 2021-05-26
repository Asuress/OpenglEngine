#ifndef SCENE_H
#define SCENE_H

#include <list>
#include "main/GameObject.h"

class Scene {
private:
    std::list<GameObject> objects;

public:
    Scene();
    ~Scene();
    void loadScene();
    void addObject(GameObject& obj);
    void callFrame();
    std::list<GameObject>::iterator getObjectsIteratorBegin();
    std::list<GameObject>::iterator getObjectsIteratorEnd();
};
#endif
