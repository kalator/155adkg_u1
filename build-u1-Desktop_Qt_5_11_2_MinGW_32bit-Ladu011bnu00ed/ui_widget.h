/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
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
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(942, 596);
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        canvas = new Draw(Widget);
        canvas->setObjectName(QStringLiteral("canvas"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(canvas->sizePolicy().hasHeightForWidth());
        canvas->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(canvas);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        load_button = new QPushButton(Widget);
        load_button->setObjectName(QStringLiteral("load_button"));

        verticalLayout->addWidget(load_button);

        loaded = new QLabel(Widget);
        loaded->setObjectName(QStringLiteral("loaded"));

        verticalLayout->addWidget(loaded);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        comboBox = new QComboBox(Widget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout->addWidget(comboBox);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        set_x = new QLineEdit(Widget);
        set_x->setObjectName(QStringLiteral("set_x"));

        verticalLayout->addWidget(set_x);

        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        set_y = new QLineEdit(Widget);
        set_y->setObjectName(QStringLiteral("set_y"));

        verticalLayout->addWidget(set_y);

        set_coords_button = new QPushButton(Widget);
        set_coords_button->setObjectName(QStringLiteral("set_coords_button"));

        verticalLayout->addWidget(set_coords_button);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        analyze_button = new QPushButton(Widget);
        analyze_button->setObjectName(QStringLiteral("analyze_button"));

        verticalLayout->addWidget(analyze_button);

        result = new QLabel(Widget);
        result->setObjectName(QStringLiteral("result"));

        verticalLayout->addWidget(result);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        clear_button = new QPushButton(Widget);
        clear_button->setObjectName(QStringLiteral("clear_button"));

        verticalLayout->addWidget(clear_button);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Point in polygon", nullptr));
        load_button->setText(QApplication::translate("Widget", "Load polygon", nullptr));
        loaded->setText(QString());
        label->setText(QApplication::translate("Widget", "Method", nullptr));
        comboBox->setItemText(0, QApplication::translate("Widget", "Winding Number", nullptr));
        comboBox->setItemText(1, QApplication::translate("Widget", "Ray Crossing", nullptr));

        label_2->setText(QApplication::translate("Widget", "set X", nullptr));
        set_x->setText(QString());
        label_3->setText(QApplication::translate("Widget", "set Y", nullptr));
        set_y->setText(QString());
        set_coords_button->setText(QApplication::translate("Widget", "Set coords of point", nullptr));
        analyze_button->setText(QApplication::translate("Widget", "Analyze", nullptr));
        result->setText(QString());
        clear_button->setText(QApplication::translate("Widget", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
