#pragma once
#include "Shape.h"
#include "pch.h"

class CLIPPING_API Clipping
{
public:
	Clipping(Shape region, Shape polygon);
	~Clipping();
	Shape getClippedPolygon();

private:
	void clipAlongLine(Line l);
	double xIntersect(Line l1, Line l2);
	double yIntersect(Line l1, Line l2);

private:
	Shape mPolygon;
	Shape mRegion;  //clipping area
};
