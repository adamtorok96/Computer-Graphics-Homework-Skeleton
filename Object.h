#ifndef OPENGL_TEST_OBJECT_H
#define OPENGL_TEST_OBJECT_H

#include <GL/glew.h>

#include "Intersectable.h"
#include "Camera.h"

class Object : public Intersectable {

    float scaleX, scaleY;
    float translationX, translationY;

public:

    unsigned int vao;

    Object();

    virtual void create();
    virtual void draw(Camera &camera, unsigned int shaderProgram) = 0;

    virtual void control() = 0;
    virtual void animate(float t) = 0;

    void transform(Camera &camera, unsigned int shaderProgram);
    void scale(float x, float y);
    void translate(float x, float y);
};


#endif //OPENGL_TEST_OBJECT_H
