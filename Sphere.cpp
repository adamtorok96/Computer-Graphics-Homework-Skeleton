#include "Sphere.h"

Hit Sphere::intersect(const Ray& ray) {
    double a =
            ray.dir.x * ray.dir.x +
            ray.dir.y * ray.dir.y +
            ray.dir.z * ray.dir.z;

    double b =
            2 * ray.dir.x * (ray.start.x - center.x) +
            2 * ray.dir.y * (ray.start.y - center.y) +
            2 * ray.dir.z * (ray.start.z - center.z);

    double c =
            center.x * center.x +
            center.y * center.y +
            center.z * center.z +
            ray.start.x * ray.start.x +
            ray.start.y * ray.start.y +
            ray.start.z * ray.start.z -
            2 * (
                        center.x * ray.start.x +
                        center.y * ray.start.y +
                        center.z * ray.start.z
                ) -
            radius * radius;

    double d = b * b - 4 * a * c;

    if(d < 0) {
        return Hit(-1);
    }

    double t = ((-1.0 * b - sqrt(d)) / (2.0 * a));

    Hit hit((float)t);
    hit.position    = ray.start + ray.dir * t;
    hit.material    = material;
    hit.normal      = (hit.position - center).normalize();

    return hit;
}