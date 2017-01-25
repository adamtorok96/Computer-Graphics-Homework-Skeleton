#ifndef OPENGL_TEST_SMOOTHMATERIAL_H
#define OPENGL_TEST_SMOOTHMATERIAL_H

#include "vec3.h"

class SmoothMaterial {
    vec3   F0;	// F0 spektrum
    float  n;	// Hullámhosszfüggéstől eltekintünk! Miért tehetjük meg?
public:
    vec3 reflect(vec3 inDir, vec3 normal);
    vec3 refract(vec3 inDir, vec3 normal);
    vec3 Fresnel(vec3 inDir, vec3 normal);
};


#endif //OPENGL_TEST_SMOOTHMATERIAL_H
