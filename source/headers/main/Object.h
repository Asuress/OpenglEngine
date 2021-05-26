#ifndef OBJECT_H
#define OBJECT_H

#include "graphics/IRenderable.h"

class Object : public IRenderable {
private:

public:
    bool isVisible;
    Object();
    ~Object();
    virtual void collisionCheck() {};
    virtual void fixedUpdate() {};
    virtual void earlyUpdate() {};
    virtual void update() {};
    virtual void lateUpdate() {};
    virtual void display() {};
};

#endif
