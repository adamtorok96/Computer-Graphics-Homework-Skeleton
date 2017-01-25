#include "LagrangeCurve.h"

float LagrangeCurve::L(int i, float t) {
    float Li = 1.0f;

    for(int j = 0; j < cps.size(); j++)
        if (j != i)
            Li *= (t - ts[j]) / (ts[i] - ts[j]);;

    return Li;
}

void LagrangeCurve::AddControlPoint(vec3 cp) {
    float ti = cps.size(); 	// or something better
    cps.push_back(cp); ts.push_back(ti);
}

vec3 LagrangeCurve::r(float t) {
    vec3 rr(0, 0, 0);

    for(int i = 0; i < cps.size(); i++)
        rr += cps[i] * L(i,t);

    return rr;
}