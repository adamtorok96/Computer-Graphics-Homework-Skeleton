#ifndef OPENGL_TEST_TRIANGLE_H
#define OPENGL_TEST_TRIANGLE_H

#include <cstdio>

#include <GL/glew.h>

#include "mat4.h"
#include "Camera.h"
#include "Object.h"

class Triangle : public Object {
    unsigned int vao;	// vertex array object id
    float sx, sy;		// scaling
    float wTx, wTy;		// translation

public:
    Triangle() {
        Animate(0);
    }

    void create();
    void animate(float t);
    void draw(Camera &camera, unsigned int shaderProgram);
};


#endif //OPENGL_TEST_TRIANGLE_H
