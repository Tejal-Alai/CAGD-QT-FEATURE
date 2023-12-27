#pragma once
#include "Point.h"
#include "pch.h"
#include <vector>


using namespace std;

class BEZEIRCURVE_API BezeirCurve
{
public:
	BezeirCurve(Point inP0, Point inP1, Point inP2, Point inP3);
	~BezeirCurve();

	void drawCurve(Point inP0, Point inP1, Point inP2, Point inP3, std::vector<float>& mVertices, std::vector<float>& mColors);

private:
	Point mP0;
	Point mP1;
	Point mP2;
	Point mP3;

	float blend1;
	float blend2;
	float blend3;
	float blend4;
};

