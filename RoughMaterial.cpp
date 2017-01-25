#include "RoughMaterial.h"

vec3 RoughMaterial::shade(vec3 normal, vec3 viewDir, vec3 lightDir, vec3 inRad) {
    float cosTheta = dot(normal, lightDir);

    if(cosTheta < 0)
        return vec3(0, 0, 0);

    vec3 difRad = inRad * kd * cosTheta;;
    vec3 halfway = (viewDir + lightDir).normalize();

    float cosDelta = dot(normal, halfway);

    if(cosDelta < 0)
        return difRad;

    return difRad + inRad * ks * pow(cosDelta, shininess);
}