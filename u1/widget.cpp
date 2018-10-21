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
    ui->result->setText("");
}

void Widget::on_pushButton_2_clicked()
{
    QPointF q = ui->canvas->getQ();

    //get polygons one by one
    int polygon_count = ui->canvas->getNumberOfPolygons();
    std::vector<int> results;

    //flag for setting output (if point is inside/outside/on boundary)
    bool write_result = true;

    //use algorithm according to user choice

    //Ray algorithm
    if(ui->comboBox->currentIndex())
    {
        for(unsigned k = 0; k < polygon_count; k++)
        {
            std::vector<QPointF> pol = ui->canvas->getPol(k);
            results.push_back(Algorithms::getPositionRay(q, pol));

            //send to output wheather point is in/out/on the boundari(es)
            analysisResult(results[k], write_result);
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

            //send to output wheather point is in/out/on the boundari(es)
            analysisResult(results[k], write_result);
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
    if(ui->set_x->text().isEmpty() || ui->set_y->text().isEmpty())
        return;

    ui->canvas->setPointCoords(ui->set_x->text().toDouble(), ui->set_y->text().toDouble());
}

void Widget::analysisResult(int result, bool &write_result)
{
    //send to output wheather point is in/out/on the boundari(es)
    if(result == 1 && write_result)
    {
        ui->result->setText("Point is in polygon.");
        write_result = false; // I do not want to check that anymore, bcs I know already
    }
    else if(result == 0 && write_result)
    {
        ui->result->setText("Point is out.");
    }
    else if(result == -1 && write_result)
    {
        ui->result->setText("Point on boundary.");
        write_result = false;
    }
}
