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

class Draw : public QWidget
{
    Q_OBJECT

private:
    QPointF q;
    std::vector<QPoint> pol;
    std::vector<std::vector<QPointF>> poly_pol;
   // qreal x_min, y_min, x_max, y_max;
   // qreal scale;

public:
    explicit Draw(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);
   // void resizeEvent(QResizeEvent *e);
    void clearCanvas();
    bool loadPolygon(std::string &path, QString &msg, QSize canvas_size);
    //void setMinMax(qreal x, qreal y);
    QPointF getQ() {return q};
    std::vector<QPointF> getPol {return poly_pol};

signals:

public slots:
};

#endif // DRAW_H
