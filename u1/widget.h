#ifndef WIDGET_H
#define WIDGET_H

#include "ui_widget.h"
#include "algorithms.h"

#include <QWidget>
#include <QFileDialog>
#include <string>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void analysisResult(int result, bool &write_result);

private slots:
    void on_clear_button_clicked();

    void on_analyze_button_clicked();

    void on_load_button_clicked();

    void on_set_coords_button_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
