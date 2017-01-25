#ifndef OPENGL_TEST_HIT_H
#define OPENGL_TEST_HIT_H

#include "vec3.h"

struct Hit {
    float t;
    vec3 position;
    vec3 normal;
//    Material* material;
 //   Hit() { t = -1; }
};

#endif //OPENGL_TEST_HIT_H
