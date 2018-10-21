#include "draw.h"

Draw::Draw(QWidget *parent) : QWidget(parent)
{
    //set initial possition of point q
    q.setX(-5);
    q.setY(-5);
}

void Draw::paintEvent(QPaintEvent *e)
{
    //Draw polygons and point, highlight polygons that contain point

    //with this constructor, begin/end does not have to be called
    QPainter painter(this);

    //set pen for initial polygon drawing
    QPen pen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen);

    //draw polygons from file
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
        if(analysis_results[i]) //if point is inside or on the boundary
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

    //Draw q - at the end of method for preventing polygon filling to be drawn accross point q
    painter.setPen(pen);
    painter.drawEllipse(q.x()-5, q.y()-5, 10, 10);
}

void Draw::mousePressEvent(QMouseEvent *e)
{
    setPointCoords(e->x(), e->y());
}

void Draw::setPointCoords(double x, double y)
{
    //set possition of point q
    q.setX(x);
    q.setY(y);

    repaint();
}

void Draw::clearCanvas()
{
    poly_pol.clear();

    //reset point q placement
    q.setX(-5);
    q.setY(-5);

    analysis_results.clear();
    repaint();
}

bool Draw::loadPolygon(std::string &path, QString &msg)
{
    std::ifstream poly_file;
    poly_file.open(path);

    //check if poly_file is correctly open (or if it exists)
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

    //go through file and load points into poly_pol (storing all polygons)
    while(poly_file.good() && no_of_poly--)
    {
        //get number of points in one polygon
        poly_file >> no_of_points;

        //check for invalid polygons
        if(no_of_points < 3)
        {
            msg = "Polygon with less then  \r\n3 vertices detected!";
            poly_file.close();
            poly_pol.clear(); //clear points that were added so far
            return 0;
        }

        //go through points of one polygon, save it into one_poly
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

        poly_pol.push_back(one_poly); //save new polygon to poly_pol
        one_poly.clear();
    }

    poly_file.close();

    msg = "Success!";
    return 1;
}

std::vector<QPointF> Draw::getPol(int index)
{
    return poly_pol[index];
}

void Draw::fillPolygon(std::vector<int> analysis_results)
{
    //fill polygons containing point q with colour
    this->analysis_results = analysis_results;
    repaint();
}
