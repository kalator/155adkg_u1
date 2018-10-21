#ifndef DRAW_H
#define DRAW_H

#include <QWidget>
#include <vector>
#include <QtGui>
#include <fstream>
#include <string>
#include <iostream>
#include <QPainterPath>
#include <QBrush>
#include <QPen>

class Draw : public QWidget
{
    Q_OBJECT

private:
    QPointF q; //point for which position is determined
    std::vector<std::vector<QPointF>> poly_pol; //vector of polygon points
    std::vector<int> analysis_results; //contains results of point-polygon possition analysis for each polygon

public:
    explicit Draw(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void fillPolygon(std::vector<int> analysis_results); //highlight polygon containing point q
    void clearCanvas();
    bool loadPolygon(std::string &path, QString &msg); //load polygon from file
    QPointF getQ() {return q;} //get coordinates of point q
    std::vector<QPointF> getPol(int index); //get polygon according to given index
    int getNumberOfPolygons() {return poly_pol.size();} //how many polygons there are in canvas
    void setPointCoords(double x, double y); //set coordinates of point q

signals:

public slots:
};

#endif // DRAW_H
