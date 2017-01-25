#ifndef OPENGL_TEST_OBJECT_H
#define OPENGL_TEST_OBJECT_H


#include "Intersectable.h"
#include "Camera.h"

class Object : public Intersectable {

public:

    virtual void generate() = 0;
    virtual void draw(Camera &camera, unsigned int shaderProgram) = 0;

    virtual void control() = 0;
    virtual void animate() = 0;

};


#endif //OPENGL_TEST_OBJECT_H
