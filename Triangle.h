#ifndef OPENGL_TEST_TRIANGLE_H
#define OPENGL_TEST_TRIANGLE_H

#include <cstdio>

#include <GL/glew.h>

#include "mat4.h"
#include "Camera.h"
#include "Object.h"

class Triangle : public Object {

    vec3 a, b, c;
    vec3 color;

public:
    Triangle(vec3 a, vec3 b, vec3 c, vec3 color);

    void create();
    void draw(Camera &camera, unsigned int shaderProgram);

    void control();
    void animate(float t);

    Hit intersect(const Ray &ray);
};


#endif //OPENGL_TEST_TRIANGLE_H
