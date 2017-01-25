#include "BezierCurve.h"

float BezierCurve::B(int i, float t) {
    int n = cps.size()-1; // n deg polynomial = n+1 pts!
    float choose = 1;
    for(int j = 1; j <= i; j++) choose *= (float)(n-j+1)/j;
    return choose * pow(t, i) * pow(1-t, n-i);
}

void BezierCurve::AddControlPoint(vec3 cp) {
    cps.push_back(cp);
}

vec3 BezierCurve::r(float t) {
    vec3 rr(0, 0, 0);

    for(int i = 0; i < cps.size(); i++)
        rr += cps[i] * B(i,t);

    return rr;
}