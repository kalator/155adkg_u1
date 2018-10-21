#include "widget.h"

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

void Widget::on_clear_button_clicked()
{
    ui->canvas->clearCanvas();
    ui->result->setText("");
}

void Widget::on_analyze_button_clicked()
{
    qDebug() << "Analyze!";
    QPointF q = ui->canvas->getQ();

    //get polygons one by one
    int polygon_count = ui->canvas->getNumberOfPolygons();

    //results of analysis for each polygon will be stored here
    std::vector<int> results;

    //flag for setting output (if point is inside/outside/on boundary), on false, output will not be changed
    bool write_result = true;

    //use algorithm according to user choice

    //Ray algorithm
    if(ui->comboBox->currentIndex())
    {
        //go through all polygons
        for(int k = 0; k < polygon_count; k++)
        {
            std::vector<QPointF> pol = ui->canvas->getPol(k);

            //get result of analysis for one polygon
            results.push_back(Algorithms::getPositionRay(q, pol));

            //send to output wheather point is in/out/on the boundari(es)
            analysisResult(results[k], write_result);

            //we do not have to continue analyzing when point q is foung lying inside of one of polygons
            if(results[k] == 1)
            {
                break;
            }
        }

        //highlight polygons with point q inside (on the boundary)
        ui->canvas->fillPolygon(results);
    }

    //Winding algorithm
    else
    {
        //go through all polygons
        for(int k = 0; k < polygon_count; k++)
        {
            std::vector<QPointF> pol = ui->canvas->getPol(k);

            //get result of analysis for one polygon
            results.push_back(Algorithms::getPositionWinding(q, pol));

            //send to output wheather point is in/out/on the boundari(es)
            analysisResult(results[k], write_result);

            //we do not have to continue analyzing when point q is foung lying inside of one of polygons
            if(results[k] == 1)
            {
                break;
            }
        }

        //highlight polygons with point q inside (on the boundary)
        ui->canvas->fillPolygon(results);
    }
    results.clear();
}

void Widget::on_load_button_clicked()
{
    //open file dialog
    QString poly_path = QFileDialog::getOpenFileName(
                this,
                tr("Select file"),
                "/",
                "Text file (*.txt);;All files (*.*)");

    //convert path from QString to string (change coding to utf8 for ifstream)
    std::string poly_path_utf8 = poly_path.toUtf8().constData();

    //create message telling whether file was loaded correctly (or if file is valid)
    QString msg;

    if(ui->canvas->loadPolygon(poly_path_utf8, msg)) //load polygon and get load message
    {
        ui->loaded->setText(msg); //loaded correctly
    }
    else
    {
        ui->loaded->setText(msg); //not loaded (some error)
    }

}

void Widget::on_set_coords_button_clicked()
{
    //set coords from user input (not from mouse click)

    //check whether there is any number in line edits (otherwise q would be moved to initial location -5 -5)
    if(ui->set_x->text().isEmpty() || ui->set_y->text().isEmpty())
        return;

    ui->canvas->setPointCoords(ui->set_x->text().toDouble(), ui->set_y->text().toDouble());
}

void Widget::analysisResult(int result, bool &write_result)
{
    //send to output wheather point is in/out/on the boundari(es)

    //check for write_result - if true, we want to write, if false, we do not (because we know already)
    if(result == 1 && write_result)
    {
        ui->result->setText("Point is in polygon.");
        write_result = false;
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
