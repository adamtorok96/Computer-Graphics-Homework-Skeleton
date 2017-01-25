#ifndef OPENGL_TEST_MATERIAL_H
#define OPENGL_TEST_MATERIAL_H


#include "vec3.h"

class Material {
    vec3  F0;	// F0 spektrum
    float n;    // hullámhossz

    float ka;
    float kd;
    float ks;

    float shine;

    bool reflective, refractive;

public:
    Material(bool reflective, bool refractive);

    bool isReflective();
    bool isRefractive();

    vec3 reflect(vec3 inDir, vec3 normal);
    vec3 refract(vec3 inDir, vec3 normal);
    vec3 Fresnel(vec3 inDir, vec3 normal);

    vec3 shade(vec3 normal, vec3 viewDir, vec3 lightDir, vec3 inRad);

    float getKa();
};


#endif //OPENGL_TEST_MATERIAL_H
