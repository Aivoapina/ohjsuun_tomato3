/********************************************************************************
** Form generated from reading UI file 'myqframe.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYQFRAME_H
#define UI_MYQFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myQFrame
{
public:

    void setupUi(QWidget *myQFrame)
    {
        if (myQFrame->objectName().isEmpty())
            myQFrame->setObjectName(QStringLiteral("myQFrame"));
        myQFrame->resize(400, 300);

        retranslateUi(myQFrame);

        QMetaObject::connectSlotsByName(myQFrame);
    } // setupUi

    void retranslateUi(QWidget *myQFrame)
    {
        myQFrame->setWindowTitle(QApplication::translate("myQFrame", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class myQFrame: public Ui_myQFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYQFRAME_H
