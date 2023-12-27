#include "pch.h"
#include "BezeirCurve.h"

#include <cmath>

BezeirCurve::BezeirCurve(Point inP0, Point inP1, Point inP2, Point inP3) :
    mP0(inP0),
    mP1(inP1),
    mP2(inP2),
    mP3(inP2)
{

}
BezeirCurve::~BezeirCurve()
{

}

void BezeirCurve::drawCurve(Point inP0, Point inP1, Point inP2, Point inP3, vector<float>& mVertices, vector<float>& mColors)
{
    float t;

    for (t = 0; t <= 1; t += 0.001)
    {

        float x = pow(1 - t, 3) * inP0.x() + 3 * pow(1 - t, 2) * t * inP1.x() + 3 * (1 - t) * pow(t, 2) * inP2.x() + pow(t, 3) * inP3.x();
        float y = pow(1 - t, 3) * inP0.y() + 3 * pow(1 - t, 2) * t * inP1.y() + 3 * (1 - t) * pow(t, 2) * inP2.y() + pow(t, 3) * inP3.y();
        float z = pow(1 - t, 3) * inP0.z() + 3 * pow(1 - t, 2) * t * inP1.z() + 3 * (1 - t) * pow(t, 2) * inP2.z() + pow(t, 3) * inP3.z();

        mVertices.push_back(x);
        mVertices.push_back(y);
        mVertices.push_back(z);

        mVertices.push_back(x);
        mVertices.push_back(y);
        mVertices.push_back(z);

        mColors.push_back(0.0f);
        mColors.push_back(1.0f);
        mColors.push_back(0.0f);

        mColors.push_back(0.0f);
        mColors.push_back(1.0f);
        mColors.push_back(0.0f);

    }

}