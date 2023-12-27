#include "stdafx.h"
#include "Shape.h"
#include "ShapeContainer.h"

ShapeContainer::ShapeContainer() 
{
}

ShapeContainer::~ShapeContainer()
{
}

void ShapeContainer::addShape(Shape inShape)
{
	mShapes.push_back(inShape);
}
void ShapeContainer::addClippingArea(Shape inClippingArea)
{
	mClippingArea = inClippingArea;
}

std::vector<Shape>& ShapeContainer::getShapes()
{
	return mShapes;
}
Shape ShapeContainer::getClippingArea()
{
	return mClippingArea;
}