#ifndef OPENGL_TEST_HIT_H
#define OPENGL_TEST_HIT_H

#include "vec3.h"
#include "Material.h"

struct Hit {
    float t;

    vec3 position;
    vec3 normal;

    Material* material;

    Hit() {
        t = -1;
    }

    Hit(float t) {
        this->t = t;
    }
};

#endif //OPENGL_TEST_HIT_H
