#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "graphics/renderable/IRenderable.hpp"
#include "physics/IPhysical.hpp"

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
