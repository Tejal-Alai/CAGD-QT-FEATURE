#pragma once
#include "Line.h"
#include "pch.h"
#include <vector>

class GEOMETRY_API Shape
{
public:
	Shape();
	Shape(const std::vector<Line>& polyLines);
	~Shape();


	void addPoints(std::vector<Point> inPoints);
	std::vector<Point>& getPoints();

	std::vector<Line>& getShape();
	size_t getSize() const;
	void setShape(std::vector<Line> vl);

	//method for point to line
	void pointsToShape();


private:
	std::vector<Point> mPoints;
	std::vector<Line> mPolyLines;

};

