/********************************************************************************
** Form generated from reading UI file 'lintulawindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINTULAWINDOW_H
#define UI_LINTULAWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lintulaWindow
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *rahaLabel;

    void setupUi(QWidget *lintulaWindow)
    {
        if (lintulaWindow->objectName().isEmpty())
            lintulaWindow->setObjectName(QStringLiteral("lintulaWindow"));
        lintulaWindow->resize(500, 500);
        pushButton = new QPushButton(lintulaWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(100, 60, 136, 27));
        label = new QLabel(lintulaWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 331, 21));
        label_3 = new QLabel(lintulaWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(31, 61, 60, 17));
        label_4 = new QLabel(lintulaWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(31, 94, 67, 17));
        pushButton_2 = new QPushButton(lintulaWindow);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 90, 113, 27));
        widget = new QWidget(lintulaWindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 220, 99, 19));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        rahaLabel = new QLabel(widget);
        rahaLabel->setObjectName(QStringLiteral("rahaLabel"));

        horizontalLayout->addWidget(rahaLabel);


        retranslateUi(lintulaWindow);

        QMetaObject::connectSlotsByName(lintulaWindow);
    } // setupUi

    void retranslateUi(QWidget *lintulaWindow)
    {
        lintulaWindow->setWindowTitle(QApplication::translate("lintulaWindow", "Form", 0));
        pushButton->setText(QApplication::translate("lintulaWindow", "Treenaa Kest\303\244vyytt\303\244!", 0));
        label->setText(QApplication::translate("lintulaWindow", "Tervetuloa Lintulaan! T\303\244\303\244ll\303\244 voit kouluttaa plebej\303\244si", 0));
        label_3->setText(QApplication::translate("lintulaWindow", "Hinta: 250", 0));
        label_4->setText(QApplication::translate("lintulaWindow", "Hinta: 1000", 0));
        pushButton_2->setText(QApplication::translate("lintulaWindow", "Treenaa Voimaa!", 0));
        label_2->setText(QApplication::translate("lintulaWindow", "Rahaa", 0));
        rahaLabel->setText(QApplication::translate("lintulaWindow", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class lintulaWindow: public Ui_lintulaWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINTULAWINDOW_H
