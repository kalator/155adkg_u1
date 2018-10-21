/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "draw.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    Draw *canvas;
    QVBoxLayout *verticalLayout;
    QPushButton *load_button;
    QLabel *loaded;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QComboBox *comboBox;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_2;
    QLineEdit *set_x;
    QLabel *label_3;
    QLineEdit *set_y;
    QPushButton *set_coords_button;
    QSpacerItem *verticalSpacer_2;
    QPushButton *analyze_button;
    QLabel *result;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_3;
    QPushButton *clear_button;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(942, 596);
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        canvas = new Draw(Widget);
        canvas->setObjectName(QString::fromUtf8("canvas"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(canvas->sizePolicy().hasHeightForWidth());
        canvas->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(canvas);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        load_button = new QPushButton(Widget);
        load_button->setObjectName(QString::fromUtf8("load_button"));

        verticalLayout->addWidget(load_button);

        loaded = new QLabel(Widget);
        loaded->setObjectName(QString::fromUtf8("loaded"));

        verticalLayout->addWidget(loaded);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        comboBox = new QComboBox(Widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout->addWidget(comboBox);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        set_x = new QLineEdit(Widget);
        set_x->setObjectName(QString::fromUtf8("set_x"));

        verticalLayout->addWidget(set_x);

        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        set_y = new QLineEdit(Widget);
        set_y->setObjectName(QString::fromUtf8("set_y"));

        verticalLayout->addWidget(set_y);

        set_coords_button = new QPushButton(Widget);
        set_coords_button->setObjectName(QString::fromUtf8("set_coords_button"));

        verticalLayout->addWidget(set_coords_button);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        analyze_button = new QPushButton(Widget);
        analyze_button->setObjectName(QString::fromUtf8("analyze_button"));

        verticalLayout->addWidget(analyze_button);

        result = new QLabel(Widget);
        result->setObjectName(QString::fromUtf8("result"));

        verticalLayout->addWidget(result);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        clear_button = new QPushButton(Widget);
        clear_button->setObjectName(QString::fromUtf8("clear_button"));

        verticalLayout->addWidget(clear_button);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Point in polygon", 0, QApplication::UnicodeUTF8));
        load_button->setText(QApplication::translate("Widget", "Load polygon", 0, QApplication::UnicodeUTF8));
        loaded->setText(QString());
        label->setText(QApplication::translate("Widget", "Method", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "Winding Number", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "Ray Crossing", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("Widget", "set X", 0, QApplication::UnicodeUTF8));
        set_x->setText(QString());
        label_3->setText(QApplication::translate("Widget", "set Y", 0, QApplication::UnicodeUTF8));
        set_y->setText(QString());
        set_coords_button->setText(QApplication::translate("Widget", "Set coords of point", 0, QApplication::UnicodeUTF8));
        analyze_button->setText(QApplication::translate("Widget", "Analyze", 0, QApplication::UnicodeUTF8));
        result->setText(QString());
        clear_button->setText(QApplication::translate("Widget", "Clear", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
