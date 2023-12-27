//#pragma once
//#include "Point.h"
#include "pch.h"
//#include <vector>
//
//using namespace std;
//
//class BSPLINE_API BSpline
//{
//public:
//	BSpline(Point inP0, Point inP1, Point inP2, Point inP3);
//	~BSpline();
//
//	void drawCurve(Point inP0, Point inP1, Point inP2, Point inP3, std::vector<float>& mVertices, std::vector<float>& mColors);
//
//private:
//	Point mP0;
//	Point mP1;
//	Point mP2;
//	Point mP3;
//
//	float blend1;
//	float blend2;
//	float blend3;
//	float blend4;
//};
//
//#include "pch.h"
//#include <vector>
//#include <utility>
//#include "Point.h"
//
//class BSPLINECURVE_API BSpline {
//public:
//	BSpline(int degree);
//	std::vector<Point> evaluate(std::vector<Point> control_points, float t);
//private:
//	int mDegree;
//	std::vector<float> generateUniformKnots(int num_control_points);
//	float bSplineBasis(int i, int k, float t, const std::vector<float>& knots);
//};