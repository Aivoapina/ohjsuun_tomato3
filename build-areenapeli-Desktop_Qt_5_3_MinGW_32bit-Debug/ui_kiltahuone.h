/********************************************************************************
** Form generated from reading UI file 'kiltahuone.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KILTAHUONE_H
#define UI_KILTAHUONE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_kiltahuone
{
public:
    QPushButton *osta;
    QListView *listView;
    QLabel *label;
    QLabel *rahamaara;
    QFrame *selectionWidget;

    void setupUi(QWidget *kiltahuone)
    {
        if (kiltahuone->objectName().isEmpty())
            kiltahuone->setObjectName(QStringLiteral("kiltahuone"));
        kiltahuone->resize(356, 515);
        osta = new QPushButton(kiltahuone);
        osta->setObjectName(QStringLiteral("osta"));
        osta->setGeometry(QRect(30, 460, 85, 27));
        listView = new QListView(kiltahuone);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(20, 30, 256, 201));
        label = new QLabel(kiltahuone);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 470, 55, 17));
        rahamaara = new QLabel(kiltahuone);
        rahamaara->setObjectName(QStringLiteral("rahamaara"));
        rahamaara->setGeometry(QRect(220, 470, 55, 17));
        selectionWidget = new QFrame(kiltahuone);
        selectionWidget->setObjectName(QStringLiteral("selectionWidget"));
        selectionWidget->setGeometry(QRect(20, 250, 251, 181));
        selectionWidget->setFrameShape(QFrame::StyledPanel);
        selectionWidget->setFrameShadow(QFrame::Raised);

        retranslateUi(kiltahuone);

        QMetaObject::connectSlotsByName(kiltahuone);
    } // setupUi

    void retranslateUi(QWidget *kiltahuone)
    {
        kiltahuone->setWindowTitle(QApplication::translate("kiltahuone", "Form", 0));
        osta->setText(QApplication::translate("kiltahuone", "Osta", 0));
        label->setText(QApplication::translate("kiltahuone", "Rahaa:", 0));
        rahamaara->setText(QApplication::translate("kiltahuone", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class kiltahuone: public Ui_kiltahuone {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KILTAHUONE_H
