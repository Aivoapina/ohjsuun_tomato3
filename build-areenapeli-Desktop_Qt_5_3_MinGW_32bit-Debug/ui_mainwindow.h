/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <myqframe.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *startGame;
    QPushButton *kilta;
    QPushButton *lintulaButton;
    QPushButton *pushButton;
    QPushButton *exitGame;
    myQFrame *pleb1;
    QFrame *keskiWidget;
    myQFrame *pleb3;
    myQFrame *pleb2;
    myQFrame *pleb4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *rahaLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1132, 610);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        startGame = new QPushButton(centralwidget);
        startGame->setObjectName(QStringLiteral("startGame"));

        horizontalLayout->addWidget(startGame);

        kilta = new QPushButton(centralwidget);
        kilta->setObjectName(QStringLiteral("kilta"));

        horizontalLayout->addWidget(kilta);

        lintulaButton = new QPushButton(centralwidget);
        lintulaButton->setObjectName(QStringLiteral("lintulaButton"));

        horizontalLayout->addWidget(lintulaButton);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        exitGame = new QPushButton(centralwidget);
        exitGame->setObjectName(QStringLiteral("exitGame"));

        horizontalLayout->addWidget(exitGame);


        gridLayout->addLayout(horizontalLayout, 0, 1, 1, 1);

        pleb1 = new myQFrame(centralwidget);
        pleb1->setObjectName(QStringLiteral("pleb1"));
        pleb1->setMinimumSize(QSize(300, 250));
        pleb1->setFrameShape(QFrame::StyledPanel);
        pleb1->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(pleb1, 1, 0, 1, 1);

        keskiWidget = new QFrame(centralwidget);
        keskiWidget->setObjectName(QStringLiteral("keskiWidget"));
        keskiWidget->setMinimumSize(QSize(500, 0));
        keskiWidget->setFrameShape(QFrame::StyledPanel);
        keskiWidget->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(keskiWidget, 1, 1, 2, 1);

        pleb3 = new myQFrame(centralwidget);
        pleb3->setObjectName(QStringLiteral("pleb3"));
        pleb3->setMinimumSize(QSize(300, 250));
        pleb3->setFrameShape(QFrame::StyledPanel);
        pleb3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(pleb3, 1, 2, 1, 1);

        pleb2 = new myQFrame(centralwidget);
        pleb2->setObjectName(QStringLiteral("pleb2"));
        pleb2->setMinimumSize(QSize(300, 250));
        pleb2->setFrameShape(QFrame::StyledPanel);
        pleb2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(pleb2, 2, 0, 1, 1);

        pleb4 = new myQFrame(centralwidget);
        pleb4->setObjectName(QStringLiteral("pleb4"));
        pleb4->setMinimumSize(QSize(300, 250));
        pleb4->setFrameShape(QFrame::StyledPanel);
        pleb4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(pleb4, 2, 2, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        rahaLabel = new QLabel(centralwidget);
        rahaLabel->setObjectName(QStringLiteral("rahaLabel"));

        horizontalLayout_2->addWidget(rahaLabel);


        gridLayout->addLayout(horizontalLayout_2, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1132, 27));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "AreenaPippeli", 0));
        startGame->setText(QApplication::translate("MainWindow", "Areenalle", 0));
        kilta->setText(QApplication::translate("MainWindow", "Kiltaan", 0));
        lintulaButton->setText(QApplication::translate("MainWindow", "Lintula", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Kauppaan", 0));
        exitGame->setText(QApplication::translate("MainWindow", "Exit", 0));
        label_2->setText(QApplication::translate("MainWindow", "Rahaa:", 0));
        rahaLabel->setText(QApplication::translate("MainWindow", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
