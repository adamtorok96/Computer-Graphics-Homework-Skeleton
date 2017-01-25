#include "Camera.h"

Camera::Camera() {
    Animate(0);
}

mat4 Camera::V() { // view matrix: translates the center to the origin
    return mat4(1, 0, 0, 0,
                0, 1, 0, 0,
                0, 0, 1, 0,
                -x, -y, 0, 1);
}

mat4 Camera::P() { // projection matrix: scales it to be a square of edge length 2
    return mat4(2 / width, 0, 0, 0,
                0, 2 / height, 0, 0,
                0, 0, 1, 0,
                0, 0, 0, 1);
}

mat4 Camera::Vinv() { // inverse view matrix
    return mat4(1, 0, 0, 0,
                0, 1, 0, 0,
                0, 0, 1, 0,
                x, y, 0, 1);
}

mat4 Camera::Pinv() { // inverse projection matrix
    return mat4(width / 2, 0, 0, 0,
                0, height / 2, 0, 0,
                0, 0, 1, 0,
                0, 0, 0, 1);
}

void Camera::Animate(float t) {
    x = 10 * cosf(t);
    y = 0;
    width = 20;
    height = 20;
}