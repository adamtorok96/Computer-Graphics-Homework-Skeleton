//
// Created by edems on 2017.01.25..
//

#ifndef OPENGL_TEST_PLANE_H
#define OPENGL_TEST_PLANE_H


#include "Intersectable.h"
#include "vec3.h"

class Plane : public Intersectable {

public:
    vec3 point;
    vec3 normal;
    float d;

    Plane(vec3 point, vec3 normal);
    Hit intersect(const Ray& ray);
};


#endif //OPENGL_TEST_PLANE_H
