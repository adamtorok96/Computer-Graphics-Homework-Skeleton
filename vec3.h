#ifndef OPENGL_TEST_VEC3_H
#define OPENGL_TEST_VEC3_H

#include <cmath>

class vec3 {

public:
    float x, y, z;

    vec3();
    vec3(float x, float y, float z);

    vec3 operator*(float a);
    vec3 operator/(float n);

    vec3 operator+(const vec3& v);
    vec3 operator-(const vec3& v);
    vec3 operator*(const vec3& v);

    vec3& operator+=(const vec3& v);
    vec3& operator/=(float n);

    float length();
    float dot(const vec3& v);

    vec3 normalize();
    vec3 cross(const vec3& v);
};



#endif //OPENGL_TEST_VEC3_H
