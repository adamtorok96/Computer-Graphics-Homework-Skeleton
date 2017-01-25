#include "vec3.h"

vec3::vec3() {
    x = 0;
    y = 0;
    z = 0;
}

vec3::vec3(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

vec3 vec3::operator*(float n) {
    return vec3(x * n, y * n, z * n);
}

vec3 vec3::operator/(float n) {
    return n == 0 ? vec3(x, y, z) : vec3(x / n, y / n, z / n);
}

vec3 vec3::operator+(const vec3& v) {
    return vec3(x + v.x, y + v.y, z + v.z);
}

vec3 vec3::operator-(const vec3& v) {
    return vec3(x - v.x, y - v.y, z - v.z);
}

vec3 vec3::operator*(const vec3& v) {
    return vec3(x * v.x, y * v.y, z * v.z);
}

vec3& vec3::operator+=(const vec3& v) {
    x += v.x;
    y += v.y;
    z += v.z;

    return *this;
}

vec3& vec3::operator/=(float n) {
    if( n != 0 ) {
        x /= n;
        y /= n;
        z /= n;
    }

    return *this;
}

float vec3::length() {
    return sqrtf(x * x + y * y + z * z);
}

vec3 vec3::normalize() {
    float length = length();

    return length == 0 ? vec3(x, y, z) : vec3(x / length, y / length, z / length);
}

float vec3::dot(const vec3& v) {
    return (x * v.x + y * v.y + z * v.z);
}

vec3 vec3::cross(const vec3& v) {
    return vec3(
            v.y * z - v.z * y,
            v.z * x - v.x * z,
            v.x * y - v.y * x
    );
}