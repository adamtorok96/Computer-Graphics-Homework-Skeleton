#include "SmoothMaterial.h"

vec3 SmoothMaterial::reflect(vec3 inDir, vec3 normal) {
    return inDir - normal * dot(normal, inDir) * 2.0f;
}

vec3 SmoothMaterial::refract(vec3 inDir, vec3 normal) {
    float ior = n;

    float cosa = -dot(normal, inDir);

    if (cosa < 0) {
        cosa = -cosa;
        normal = normal * (-1);
        ior = 1 / n;

        float disc = 1 - (1 - cosa * cosa) / ior / ior;

        if (disc < 0)
            return reflect(inDir, normal); // total reflect

        return inDir / ior + normal * (cosa / ior - sqrt(disc));
    }
}

vec3 SmoothMaterial::Fresnel(vec3 inDir, vec3 normal) { // közelítés
    float cosa = (float) fabs(dot(normal, inDir));

    return F0 + (vec3(1, 1, 1) - F0) * pow(1-cosa, 5);
}