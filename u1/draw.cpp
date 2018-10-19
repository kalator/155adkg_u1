#include "draw.h"

Draw::Draw(QWidget *parent) : QWidget(parent)
{
    q.setX(120.3);
    q.setY(20.1);

    /*
    x_min = std::numeric_limits<qreal>::max();
    y_min = std::numeric_limits<qreal>::max();
    x_max = std::numeric_limits<qreal>::min();
    y_max = std::numeric_limits<qreal>::min();
    */
}

void Draw::paintEvent(QPaintEvent *e)
{
    //Draw polygon and point
    QPainter painter(this);

    //Start drawing
    painter.begin(this);

    //set pen
    QPen pen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen);

    //set scale
    // painter.scale(scale, scale);
    //painter.translate(10,10);

    for(unsigned j = 0; j < poly_pol.size(); j++)
    {
        //Create polygon
        QPolygonF p;

        //Current polygon from file
        std::vector<QPointF> current_pol = poly_pol[j];

        //Add points to the polygon
        for(unsigned int i = 0; i < current_pol.size(); i++)
        {
            p.append(current_pol[i]);
        }

        //Draw polygon
        painter.drawPolygon(p);
    }

    //fill polygon with color
    //set pen
    QPen pen2(Qt::red, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen2);

    //set fill color and style
    QBrush brush;
    brush.setColor(Qt::green);
    brush.setStyle(Qt::CrossPattern);
    QPainterPath path;

    QPolygonF poly;

    for(unsigned i = 0; i < analysis_results.size(); i++)
    {
        if(analysis_results[i])
        {
            qDebug() << "Drawing polygon number " << i;
            std::vector<QPointF> pol_to_fill = poly_pol[i];
            for(unsigned l = 0; l < pol_to_fill.size(); l++)
            {
                poly << pol_to_fill[l];
            }
            path.addPolygon(poly);
            painter.drawPolygon(poly);
            painter.fillPath(path, brush);
        }
    }

    //set pen back to normal (for drawing of point q)
    painter.setPen(pen);

    //Draw q
    painter.drawEllipse(q.x()-5, q.y()-5, 10, 10);

    painter.end();
}

void Draw::mousePressEvent(QMouseEvent *e)
{
    q.setX(e->x());
    q.setY(e->y());
    repaint();
}

void Draw::clearCanvas()
{
    poly_pol.clear();
    pol.clear();
    q.setX(-5);
    q.setY(-5);
    analysis_results.clear();
    repaint();
}

bool Draw::loadPolygon(std::string &path, QString &msg, QSize canvas_size)
{
    std::ifstream poly_file;
    poly_file.open(path);

    if(!poly_file.is_open())
    {
        poly_file.close();
        msg = "Couldn't load file.";
        return 0;
    }

    //get number of polygons
    int no_of_poly;
    poly_file >> no_of_poly;

    //check whether no_of_poly is greater then 0
    if(no_of_poly < 1)
    {
        msg = "No polygon found.";
        poly_file.close();
        return 0;
    }

    //declare number of points variable
    int no_of_points;

    //declare vector for polygon points
    std::vector<QPointF> one_poly;

    while(poly_file.good() && no_of_poly--)
    {
        poly_file >> no_of_points;

        //check for invalid polygons
        if(no_of_points < 3)
        {
            msg = "Polygon with less then  \r\n3 vertices detected!";
            poly_file.close();
            return 0;
        }

        while(no_of_points--)
        {
            QPointF bod;
            qreal bod_x, bod_y;
            poly_file >> bod_x;
            poly_file >> bod_y;
            bod.setX(bod_x);
            bod.setY(bod_y);
            one_poly.push_back(bod);

            /*
            //check for max/min x/y for resize
            setMinMax(bod_x, bod_y);
            */

        }

        poly_pol.push_back(one_poly);
        one_poly.clear();
    }

    poly_file.close();

    /*
    //get scale
    (x_max - x_min) > (y_max - y_min) ? scale = (x_max - x_min): scale = (y_max - y_min);
    scale = canvas_size.height()/scale;
    */

    return 1;
}

std::vector<QPointF> Draw::getPol(int pol)
{
    return poly_pol[pol];
}

void Draw::fillPolygon(std::vector<int> analysis_results)
{
    this->analysis_results = analysis_results;
    for(unsigned i = 0; i < analysis_results.size(); i++)
    {
        qDebug() << "Result " << i << " is " << analysis_results[i];
    }
    repaint();
}

/*
void Draw::setMinMax(qreal x, qreal y)
{
    if(x > x_max) x_max = x;

    if(x < x_min) x_min = x;

    if(y > y_max) y_max = y;

    if(y < y_min) y_min = y;
}

void Draw::resizeEvent(QResizeEvent *e)
{
    repaint();
}
*/
