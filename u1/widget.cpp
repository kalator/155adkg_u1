#include "widget.h"
#include "ui_widget.h"
#include "algorithms.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_3_clicked()
{
    ui->canvas->clearCanvas();
}

void Widget::on_pushButton_2_clicked()
{
    //set off filling of the polygon containing point q
    ui->canvas->fillPolygon(-1);

    //Analyze point and polygon position
    QPointF q = ui->canvas->getQ();

    //get polygons one by one
    int polygon_count = ui->canvas->getNumberOfPolygons();
    int *results = new int[polygon_count];

    while(polygon_count--)
    {
        std::vector<QPointF> pol = ui->canvas->getPol(polygon_count); //getting polygons backwards, but that doesn't matter
        results[polygon_count] = Algorithms::getPositionRay(q, pol);
        if(results[polygon_count])
            ui->canvas->fillPolygon(polygon_count);
    }

    delete results;

  /*  if(res)
        ui->result->setText("Inside");
    else if(!res)
        ui->result->setText("Outside");
    else
        ui->result->setText("Boundary");*/
}

void Widget::on_pushButton_4_clicked()
{
    QString poly_path = QFileDialog::getOpenFileName(
                this,
                tr("Select file"),
                "/",
                "Text file (*.txt);;All files (*.*)");

    std::string poly_path_utf8 = poly_path.toUtf8().constData();

    QString msg;

    QSize canvas_size = ui->canvas->size();

    if(ui->canvas->loadPolygon(poly_path_utf8, msg, canvas_size))
    {
        ui->loaded->setText("Success!");
    }
    else
    {
        ui->loaded->setText(msg);
    }

}


