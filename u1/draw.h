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
    int poly_to_fill;
   // qreal x_min, y_min, x_max, y_max;
   // qreal scale;

public:
    explicit Draw(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void fillPolygon(int pol);
   // void resizeEvent(QResizeEvent *e);
    void clearCanvas();
    bool loadPolygon(std::string &path, QString &msg, QSize canvas_size);
    //void setMinMax(qreal x, qreal y);
    QPointF getQ() {return q;}
    std::vector<QPointF> getPol(int pol);
    int getNumberOfPolygons() {return poly_pol.size();}

signals:

public slots:
};

#endif // DRAW_H
