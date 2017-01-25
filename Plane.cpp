#include "Plane.h"

Plane::Plane(vec3 point, vec3 normal) {
    this->point = point;
    this->normal = normal;

    d = -1 * (
                normal.x * point.x +
                normal.y * point.y +
                normal.z * point.z
             );
}

Hit Plane::intersect(const Ray& ray) {
    float t = -(ray.start.dot(normal) + d) / ray.dir.dot(normal);

    Hit hit(t);
    hit.position = ray.start + ray.dir * t;
    hit.normal = ray.dir * -1;

    return hit;
}