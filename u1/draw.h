#ifndef DRAW_H
#define DRAW_H

#include <QWidget>
#include <vector>
#include <QtGui>
#include <fstream>
#include <string>
#include <QDebug>
#include <iostream>
#include <QResizeEvent>
#include <QPainterPath>
#include <QBrush>
#include <QPen>

class Draw : public QWidget
{
    Q_OBJECT

private:
    QPointF q;
    std::vector<QPoint> pol;
    std::vector<std::vector<QPointF>> poly_pol;
    std::vector<int> analysis_results;

public:
    explicit Draw(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void fillPolygon(std::vector<int> analysis_results);
    void clearCanvas();
    bool loadPolygon(std::string &path, QString &msg);
    QPointF getQ() {return q;}
    std::vector<QPointF> getPol(int pol);
    int getNumberOfPolygons() {return poly_pol.size();}
    void setPointCoords(double x, double y);

signals:

public slots:
};

#endif // DRAW_H
