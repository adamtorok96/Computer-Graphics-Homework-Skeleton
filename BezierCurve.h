#ifndef OPENGL_TEST_BEZIERCURVE_H
#define OPENGL_TEST_BEZIERCURVE_H

#include <vector>

#include "vec3.h"

using namespace std;

class BezierCurve {
    vector<vec3> cps;	// control points

    float B(int i, float t);
public:
    void AddControlPoint(vec3 cp);
    vec3 r(float t);
};


#endif //OPENGL_TEST_BEZIERCURVE_H
