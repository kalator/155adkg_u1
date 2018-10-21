#include "draw.h"

Draw::Draw(QWidget *parent) : QWidget(parent)
{
    q.setX(-5);
    q.setY(-5);
}

void Draw::paintEvent(QPaintEvent *e)
{
    //Draw polygon and point, with this constructor, begin/end does not have to be called
    QPainter painter(this);

    //set pen
    QPen pen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen);

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

    //Draw q
    painter.drawEllipse(q.x()-5, q.y()-5, 10, 10);

    //fill polygon with color
    //set pen
    QPen pen_fill(Qt::red, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen_fill);

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
            std::vector<QPointF> pol_to_fill = poly_pol[i];
            for(unsigned l = 0; l < pol_to_fill.size(); l++)
            {
                poly << pol_to_fill[l];
            }
            path.addPolygon(poly);
            painter.drawPolygon(poly);
            painter.fillPath(path, brush);
            poly.clear();
        }
    }
}

void Draw::mousePressEvent(QMouseEvent *e)
{
    setPointCoords(e->x(), e->y());
}

void Draw::setPointCoords(double x, double y)
{
    q.setX(x);
    q.setY(y);
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
        }

        poly_pol.push_back(one_poly);
        one_poly.clear();
    }

    poly_file.close();

    return 1;
}

std::vector<QPointF> Draw::getPol(int pol)
{
    return poly_pol[pol];
}

void Draw::fillPolygon(std::vector<int> analysis_results)
{
    this->analysis_results = analysis_results;
    repaint();
}
