#ifndef OBJECT_H
#define OBJECT_H

#include "graphics/IRenderable.h"
#include "physics/IPhysical.h"

class GameObject : public IRenderable, public IPhysical {
private:
public:
    bool isVisible;
    GameObject();
    ~GameObject();
    virtual void collisionCheck() {};
    virtual void fixedUpdate() {};
    virtual void earlyUpdate() {};
    virtual void update() {};
    virtual void lateUpdate() {};
    virtual void display() {};
};

#endif
