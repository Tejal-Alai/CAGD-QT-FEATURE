#pragma once
#include "pch.h"
#include "Point.h"

class GEOMETRY_API Line
{
public:
    Line(Point p1, Point p2);
    Line(const Line& other);
    ~Line();
    Line& operator=(const Line&);

    Point& p1();
    Point& p2();

private:
    Point mP1;
    Point mP2;
};

