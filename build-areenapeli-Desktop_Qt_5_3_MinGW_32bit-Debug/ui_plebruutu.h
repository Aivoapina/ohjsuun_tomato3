/********************************************************************************
** Form generated from reading UI file 'plebruutu.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLEBRUUTU_H
#define UI_PLEBRUUTU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_plebRuutu
{
public:
    QLabel *Kuva;
    QLabel *hpLabel;
    QLabel *powerLabel;
    QLabel *nimiLabel;

    void setupUi(QWidget *plebRuutu)
    {
        if (plebRuutu->objectName().isEmpty())
            plebRuutu->setObjectName(QStringLiteral("plebRuutu"));
        plebRuutu->resize(270, 204);
        Kuva = new QLabel(plebRuutu);
        Kuva->setObjectName(QStringLiteral("Kuva"));
        Kuva->setGeometry(QRect(10, 10, 91, 81));
        Kuva->setFrameShape(QFrame::Box);
        Kuva->setFrameShadow(QFrame::Raised);
        hpLabel = new QLabel(plebRuutu);
        hpLabel->setObjectName(QStringLiteral("hpLabel"));
        hpLabel->setGeometry(QRect(10, 100, 91, 17));
        powerLabel = new QLabel(plebRuutu);
        powerLabel->setObjectName(QStringLiteral("powerLabel"));
        powerLabel->setGeometry(QRect(10, 130, 81, 17));
        nimiLabel = new QLabel(plebRuutu);
        nimiLabel->setObjectName(QStringLiteral("nimiLabel"));
        nimiLabel->setGeometry(QRect(130, 20, 161, 17));

        retranslateUi(plebRuutu);

        QMetaObject::connectSlotsByName(plebRuutu);
    } // setupUi

    void retranslateUi(QWidget *plebRuutu)
    {
        plebRuutu->setWindowTitle(QApplication::translate("plebRuutu", "Form", 0));
        Kuva->setText(QApplication::translate("plebRuutu", "T\303\244h\303\244n kuva", 0));
        hpLabel->setText(QApplication::translate("plebRuutu", "Hp:", 0));
        powerLabel->setText(QApplication::translate("plebRuutu", "Power:", 0));
        nimiLabel->setText(QApplication::translate("plebRuutu", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class plebRuutu: public Ui_plebRuutu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLEBRUUTU_H
