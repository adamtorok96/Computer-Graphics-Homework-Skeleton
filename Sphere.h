#ifndef OPENGL_TEST_SPHERE_H
#define OPENGL_TEST_SPHERE_H

#include "Intersectable.h"
#include "vec3.h"
#include "Ray.h"
#include "Material.h"

class Sphere : public Intersectable {
    vec3 center;
    float radius;

public:
    Hit intersect(const Ray& ray);
};


#endif //OPENGL_TEST_SPHERE_H
