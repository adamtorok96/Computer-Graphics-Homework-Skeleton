#ifndef OPENGL_TEST_CAMERA_H
#define OPENGL_TEST_CAMERA_H

#include <cmath>
#include "mat4.h"
#include "vec3.h"


struct Camera {
    float x, y;	// center in world coordinates
    float width, height;	// width and height in world coordinates

public:
    Camera();

    // TODO: kiegészteni 3. koordinátára: z !!!!
    mat4 V();
    mat4 P();
    mat4 Vinv();
    mat4 Pinv();

    vec3 getEyePosition();
    vec3 getEyeDirection();

    void Animate(float t);
};

#endif //OPENGL_TEST_CAMERA_H
