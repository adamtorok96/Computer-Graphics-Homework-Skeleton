#ifndef OPENGL_TEST_ROUGHMATERIAL_H
#define OPENGL_TEST_ROUGHMATERIAL_H

#include "vec3.h"

class RoughMaterial {
    vec3  kd, ks;
    float shininess;

public:

    vec3 shade(vec3 normal, vec3 viewDir, vec3 lightDir, vec3 inRad);
};


#endif //OPENGL_TEST_ROUGHMATERIAL_H
