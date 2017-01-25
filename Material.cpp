#include "Material.h"


Material::Material(bool reflective, bool refractive) {
    this->reflective;
    this->refractive;
}

bool Material::isReflective() {
    return reflective;
}

bool Material::isRefractive() {
    return reflective;
}

vec3 Material::reflect(vec3 inDir, vec3 normal) {
    return inDir - normal * normal.dot(inDir) * 2.0f;
}

vec3 Material::refract(vec3 inDir, vec3 normal) {
    float ior = n;

    float cosa = - normal.dot(inDir);

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

vec3 Material::Fresnel(vec3 inDir, vec3 normal) { // közelítés
    float cosa = (float) fabs(normal.dot(inDir));

    return F0 + (vec3(1, 1, 1) - F0) * pow(1-cosa, 5);
}

vec3 Material::shade(vec3 normal, vec3 viewDir, vec3 lightDir, vec3 inRad) {
    float cosTheta = normal.dot(lightDir);

    if(cosTheta < 0)
        return vec3(0, 0, 0);

    vec3 difRad = inRad * kd * cosTheta;;
    vec3 halfway = (viewDir + lightDir).normalize();

    float cosDelta = normal.dot(halfway);

    if(cosDelta < 0)
        return difRad;

    return difRad + inRad * ks * pow(cosDelta, shine);
}

float Material::getKa() {
    return ka;
}
