#ifndef IPHYSICAL_H
#define IPHYSICAL_H

class IPhysical {
public:
    virtual void collisionCheck() = 0;
    virtual void fixedUpdate() = 0;
};
#endif
