#include "algorithms.h"

Algorithms::Algorithms()
{

}

int Algorithms::getPositionRay(QPointF q, std::vector<QPointF> pol)
{
    int k = 0;
    int n = pol.size();

    double xir = pol[0].x() - q.x();
    double yir = pol[0].y() - q.y();

    for(int i=1; i < n+1; i++)
    {
        //reduce coordinates
        double xiir = pol[i%n].x() - q.x();
        double yiir = pol[i%n].y() - q.y();

        //upper halfplane
        if((yiir>0) && (yir<=0) || (yir>0) && (yiir<=0))
        {
            //right halfplane
            double xm = (xiir*yir - xir*yiir)/(yiir-yir);
            if(xm>0)
            {
                k++;
            }
        }

        xir = xiir;
        yir = yiir;

    }

    return k%2;
}

int Algorithms::getPositionWinding(QPointF q, std::vector<QPointF> pol)
{
    double eps = 1.0e-10;
    double sum_angle = 0;

    double xir = pol[0].x();
    double yir = pol[0].y();

    int n = pol.size();

    for(int i=1; i < n+1; i++)
    {
        //reduce coordinates
        double xiir = pol[i%n].x();
        double yiir = pol[i%n].y();

        //compute angle
        double angle = getTwoVectorsAngle(q.x(), q.y(), xir, yir, q.x(), q.y(), xiir, yiir);
        qDebug() << "angle is: " << angle;

        //if Q is in the left half plane
        if(getPointLinePosition(q.x(), q.y(), xir, yir, xiir, yiir) == 1)
        {
            qDebug() << "adding angle";

            sum_angle += angle;
        }
        else if(getPointLinePosition(q.x(), q.y(), xir, yir, xiir, yiir) == 0)
        {
            qDebug() << "subtracking angle";
            sum_angle -= angle;
        }
        else
        {
            qDebug() << "nothing added to the angle";
        }

        //assign coordinates
        xir = xiir;
        yir = yiir;
    }
    qDebug() << "sum_angle is: " << sum_angle;

    //point is inside of the polygon
    if(fabs(sum_angle - 360) < eps)
    {
        qDebug() << "returning 1 from winding" << (sum_angle-360);
        return 1;
    }

    //point is outside of the polygon
    else if(fabs(sum_angle) < eps)
    {
        qDebug() << "returning 0 from winding";
        return 0;
    }
    //point is on the boundary of the polygon
    else
    {
        qDebug() << "returning -1 from winding";
        return -1;
    }
}

int Algorithms::getPointLinePosition(double x, double y, double x1, double y1, double x2, double y2)
{
    double eps = 1.0e-10; //zapis v semilogaritmickem tvaru - zachovana presnost v aritmetickych operacich

    //get vectors
    double ux = x2 - x1;
    double uy = y2 - y1;
    double vx = x - x1;
    double vy = y - y1;

    //get cross product
    double t = ux*vy - uy*vx;

    //point on the line - return -1
    if(fabs(t) < eps)
        return -1;

    //point in the left halfplane
    else if(t < 0)
        return 1;

    //point in the right halfplane
    else
        return 0;
}

double Algorithms::getTwoVectorsAngle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    double ux = x2 - x1;
    double uy = y2 - y1;
    double vx = x4 - x3;
    double vy = y4 - y3;

    double dot = ux*vx + uy*vy;

    double nu = sqrt(ux*ux + uy*uy);
    double nv = sqrt(vx*vx + vy*vy);

    return acos(dot/(nu*nv))*180/M_PI;

}

