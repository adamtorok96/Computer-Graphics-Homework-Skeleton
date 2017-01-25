#ifndef OPENGL_TEST_INTERSECTABLE_H
#define OPENGL_TEST_INTERSECTABLE_H

#include "Material.h"
#include "Hit.h"
#include "Ray.h"

#ifndef EPSILON
#define EPSILON 0.0001
#endif

struct Intersectable {
    Material* material;

    virtual Hit intersect(const Ray& ray) = 0;
};

#endif //OPENGL_TEST_INTERSECTABLE_H
