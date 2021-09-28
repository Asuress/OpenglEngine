#ifndef IRENDERABLE
#define IRENDERABLE

class IRenderable {
    // IRenderable() = delete;
    // IRenderable(IRenderable&) = delete;
    // ~IRenderable() = delete;
public:
    virtual void display() = 0;
};

#endif