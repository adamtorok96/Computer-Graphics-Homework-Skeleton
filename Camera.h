#ifndef OPENGL_TEST_CAMERA_H
#define OPENGL_TEST_CAMERA_H

#include "mat4.h"

struct Camera {
    float wCx, wCy;	// center in world coordinates
    float wWx, wWy;	// width and height in world coordinates
public:
    Camera() {
        Animate(0);
    }

    mat4 V() { // view matrix: translates the center to the origin
        return mat4(1, 0, 0, 0,
                    0, 1, 0, 0,
                    0, 0, 1, 0,
                    -wCx, -wCy, 0, 1);
    }

    mat4 P() { // projection matrix: scales it to be a square of edge length 2
        return mat4(2 / wWx, 0, 0, 0,
                    0, 2 / wWy, 0, 0,
                    0, 0, 1, 0,
                    0, 0, 0, 1);
    }

    mat4 Vinv() { // inverse view matrix
        return mat4(1, 0, 0, 0,
                    0, 1, 0, 0,
                    0, 0, 1, 0,
                    wCx, wCy, 0, 1);
    }

    mat4 Pinv() { // inverse projection matrix
        return mat4(wWx / 2, 0, 0, 0,
                    0, wWy / 2, 0, 0,
                    0, 0, 1, 0,
                    0, 0, 0, 1);
    }

    void Animate(float t) {
        wCx = 0; // 10 * cosf(t);
        wCy = 0;
        wWx = 20;
        wWy = 20;
    }
};

#endif //OPENGL_TEST_CAMERA_H
