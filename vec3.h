#ifndef OPENGL_TEST_VEC3_H
#define OPENGL_TEST_VEC3_H

#include <cmath>

class vec3 {

public:
    float x, y, z;

    vec3();
    vec3(float x, float y, float z);

    vec3 operator*(float a) const;
    vec3 operator/(float n) const;

    vec3 operator+(const vec3& v) const;
    vec3 operator-(const vec3& v) const;
    vec3 operator*(const vec3& v) const;

    vec3& operator+=(const vec3& v);
    vec3& operator/=(float n);

    float length() const;
    float dot(const vec3& v) const;

    vec3 normalize() const;
    vec3 cross(const vec3& v) const;
};



#endif //OPENGL_TEST_VEC3_H
