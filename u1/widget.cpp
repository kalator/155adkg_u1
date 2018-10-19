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
    qDebug() << "Analyze clicked!";
    //Analyze point and polygon position
    QPointF q = ui->canvas->getQ();

    //get polygons one by one
    int polygon_count = ui->canvas->getNumberOfPolygons();
    std::vector<int> results;
    //set off filling of the polygon containing point q

    //ui->canvas->fillPolygon(results, false);

    //use algorithm according to user choice

    //Ray algorithm
    if(ui->comboBox->currentIndex())
    {
        for(unsigned k = 0; k < polygon_count; k++)
        {
            std::vector<QPointF> pol = ui->canvas->getPol(k);
            qDebug() << Algorithms::getPositionRay(q, pol) << " is result";
            results.push_back(Algorithms::getPositionRay(q, pol));
        }
        ui->canvas->fillPolygon(results);
    }

    //Winding algorithm
    else
    {
        for(unsigned k = 0; k < polygon_count; k++)
        {
            std::vector<QPointF> pol = ui->canvas->getPol(k);
            results.push_back(Algorithms::getPositionWinding(q, pol));
        }
        ui->canvas->fillPolygon(results);
    }
    results.clear();
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



void Widget::on_set_coords_button_clicked()
{
    bool b = 0;
    ui->canvas->setPointCoords(ui->set_x->text().toDouble(&b), ui->set_y->text().toDouble(&b));
}
