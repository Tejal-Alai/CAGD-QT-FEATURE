#include "pch.h"
#include "Shape.h"
#include <vector>

Shape::Shape(const std::vector<Line>& polyLines) : mPolyLines(polyLines)
{
}
Shape::Shape()
{

}
Shape::~Shape()
{
}

void Shape::addPoints(std::vector<Point> inPoints)
{
    mPoints = inPoints;
}

std::vector<Point>& Shape::getPoints()
{
    return mPoints;
}

std::vector<Line>& Shape::getShape()
{
    return mPolyLines;
}

void Shape::setShape(std::vector<Line> vl)
{
    mPolyLines = vl;
}

size_t Shape::getSize() const
{
    return mPolyLines.size();
}

void Shape::pointsToShape()
{

    // Clear existing lines
    mPolyLines.clear();

    // Pair consecutive points to form lines
    for (size_t i = 0; i < mPoints.size(); ++i)
    {
        mPolyLines.push_back(Line(mPoints[i], mPoints[(i + 1) % mPoints.size()]));
    }

}

