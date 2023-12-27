#include "pch.h"
#include "Clipping.h"

Clipping::Clipping(Shape region, Shape polygon)
    : mRegion(region),
    mPolygon(polygon)
{
}

Clipping::~Clipping()
{
}

Shape Clipping::getClippedPolygon()
{
    int size = mRegion.getSize();
    for (int i = 0; i < size; i++)
    {
        std::vector<Line> shape = mRegion.getShape();
        clipAlongLine(shape.at(i));
    }
    return Shape(mPolygon);
}


void Clipping::clipAlongLine(Line l)
{
    std::vector<Point> newPoints;
    int newPolySize = 0;

    for (int i = 0; i < mPolygon.getSize(); i++)
    {

        Line& li = mPolygon.getShape().at(i);
        double i_pos = (l.p2().x() - l.p1().x()) * (li.p1().y() - l.p1().y()) - (l.p2().y() - l.p1().y()) * (li.p1().x() - l.p1().x());

        double k_pos = (l.p2().x() - l.p1().x()) * (li.p2().y() - l.p1().y()) - (l.p2().y() - l.p1().y()) * (li.p2().x() - l.p1().x());

        if (i_pos < 0 && k_pos < 0)
        {
            newPoints.push_back(li.p2());
            newPolySize++;
        }
        else if (i_pos >= 0 && k_pos < 0)
        {
            double x = xIntersect(l, li);
            double y = yIntersect(l, li);
            Point p(x, y, 0);
            newPoints.push_back(p);
            newPolySize++;
            newPoints.push_back(li.p2());
            newPolySize++;
        }
        else if (i_pos < 0 && k_pos >= 0)
        {
            double x = xIntersect(l, li);
            double y = yIntersect(l, li);
            Point p(x, y, 0);
            newPoints.push_back(p);
            newPolySize++;
        }
    }

    std::vector<Line> polyLine;

    for (int i = 0; i < newPolySize; i++)
    {
        polyLine.push_back(Line(newPoints.at(i), newPoints.at((i + 1) % newPoints.size())));
    }

    mPolygon.setShape(polyLine);
}

double Clipping::xIntersect(Line l1, Line l2)
{
    double num = (l1.p1().x() * l1.p2().y() - l1.p1().y() * l1.p2().x()) * (l2.p1().x() - l2.p2().x()) - (l1.p1().x() - l1.p2().x()) * (l2.p1().x() * l2.p2().y() - l2.p1().y() * l2.p2().x());
    double den = (l1.p1().x() - l1.p2().x()) * (l2.p1().y() - l2.p2().y()) - (l1.p1().y() - l1.p2().y()) * (l2.p1().x() - l2.p2().x());
    return num / den;
}
double Clipping::yIntersect(Line l1, Line l2)
{
    double num = (l1.p1().x() * l1.p2().y() - l1.p1().y() * l1.p2().x()) * (l2.p1().y() - l2.p2().y()) - (l1.p1().y() - l1.p2().y()) * (l2.p1().x() * l2.p2().y() - l2.p1().y() * l2.p2().x());
    double den = (l1.p1().x() - l1.p2().x()) * (l2.p1().y() - l2.p2().y()) - (l1.p1().y() - l1.p2().y()) * (l2.p1().x() - l2.p2().x());
    return num / den;
}