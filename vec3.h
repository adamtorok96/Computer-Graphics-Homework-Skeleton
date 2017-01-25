#ifndef OPENGL_TEST_VEC3_H
#define OPENGL_TEST_VEC3_H

#include <cmath>

struct vec3 {
    float x, y, z;

    vec3(float x0, float y0, float z0) { x = x0; y = y0; z = z0; }

    vec3 operator*(float a) { return vec3(x * a, y * a, z * a); }

    vec3 operator+(const vec3& v) { // vektor, szín, pont + vektor
        return vec3(x + v.x, y + v.y, z + v.z);
    }

    vec3 operator-(const vec3& v) { // vektor, szín, pont - pont
        return vec3(x - v.x, y - v.y, z - v.z);
    }

    vec3 operator*(const vec3& v) {
        return vec3(x * v.x, y * v.y, z * v.z);
    }

    vec3& operator+=(const vec3& v) {
        x += v.x;
        y += v.y;
        z += v.z;

        return *this;
    }

    float Length() { return sqrtf(x * x + y * y + z * z); }
};

float dot(const vec3& v1, const vec3& v2);
vec3 cross(const vec3& v1, const vec3& v2);

#endif //OPENGL_TEST_VEC3_H
