#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include <QtGui>
#include <cmath>

class Algorithms
{
public:
    Algorithms();
    static int getPositionRay(QPointF q, std::vector<QPointF> pol);
    static int getPositionWinding(QPointF q, std::vector<QPointF> pol);
    static int getPointLinePosition(double x, double y, double x1, double y1, double x2, double y2);
    static double getTwoVectorsAngle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
};

#endif // ALGORITHMS_H
