#ifndef OPENGL_TEST_LAGRANGECURVE_H
#define OPENGL_TEST_LAGRANGECURVE_H

#include <vector>

#include "vec3.h"

using namespace std;

class LagrangeCurve {
    vector<vec3>  cps;	// control points
    vector<float> ts; 	// parameter (knot) values

    float L(int i, float t);

public:
    void AddControlPoint(vec3 cp);
    vec3 r(float t);
};


#endif //OPENGL_TEST_LAGRANGECURVE_H
