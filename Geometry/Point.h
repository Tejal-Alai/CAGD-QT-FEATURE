#pragma once
#include "pch.h"
class GEOMETRY_API Point
{
public:
    Point(double inX, double inY, double inZ);
    ~Point();

    double x() const;
    double y() const;
    double z() const;

    void setX(double x);
    void setY(double y);
    void setZ(double z);

    bool operator == (const Point& p1) const;
private:
    double mX;
    double mY;
    double mZ;
};