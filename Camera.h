#ifndef OPENGL_TEST_CAMERA_H
#define OPENGL_TEST_CAMERA_H

#include "mat4.h"

struct Camera {
    float x, y;	// center in world coordinates
    float width, height;	// width and height in world coordinates

public:
    Camera();

    mat4 V();
    mat4 P();
    mat4 Vinv();
    mat4 Pinv();

    void Animate(float t);
};

#endif //OPENGL_TEST_CAMERA_H
