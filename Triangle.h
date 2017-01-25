#ifndef OPENGL_TEST_TRIANGLE_H
#define OPENGL_TEST_TRIANGLE_H

#include <cstdio>

#include <GL/glew.h>

#include "mat4.h"
#include "Camera.h"

class Triangle {
    unsigned int vao;	// vertex array object id
    float sx, sy;		// scaling
    float wTx, wTy;		// translation

public:
    Triangle() {
        Animate(0);
    }

    void Create();
    void Animate(float t);
    void Draw(Camera &camera, unsigned int shaderProgram);
};


#endif //OPENGL_TEST_TRIANGLE_H
