#pragma once
#include "Shape.h"
#include <vector>

class ShapeContainer
{
public:
	ShapeContainer();
	~ShapeContainer();

	void addShape(Shape inShape);
	void addClippingArea(Shape inClippingArea);
	std::vector<Shape>& getShapes();
	Shape getClippingArea();

private:
	std::vector<Shape> mShapes;
	Shape mClippingArea;
};

