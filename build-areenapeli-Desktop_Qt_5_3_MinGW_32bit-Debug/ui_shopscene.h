/********************************************************************************
** Form generated from reading UI file 'shopscene.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPSCENE_H
#define UI_SHOPSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_shopscene
{
public:
    QTreeWidget *treeWidget;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QLabel *labelWEPON;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *labelHELMET;
    QLabel *labelDEFENCE;

    void setupUi(QWidget *shopscene)
    {
        if (shopscene->objectName().isEmpty())
            shopscene->setObjectName(QStringLiteral("shopscene"));
        shopscene->resize(400, 300);
        treeWidget = new QTreeWidget(shopscene);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(100, 20, 251, 141));
        gridLayoutWidget_2 = new QWidget(shopscene);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(40, 170, 241, 120));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(gridLayoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1, Qt::AlignHCenter);

        labelWEPON = new QLabel(gridLayoutWidget_2);
        labelWEPON->setObjectName(QStringLiteral("labelWEPON"));

        gridLayout_2->addWidget(labelWEPON, 3, 0, 1, 1, Qt::AlignHCenter);

        label_7 = new QLabel(gridLayoutWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 2, 0, 1, 1, Qt::AlignHCenter);

        label_8 = new QLabel(gridLayoutWidget_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 4, 0, 1, 1, Qt::AlignHCenter);

        labelHELMET = new QLabel(gridLayoutWidget_2);
        labelHELMET->setObjectName(QStringLiteral("labelHELMET"));

        gridLayout_2->addWidget(labelHELMET, 1, 0, 1, 1, Qt::AlignHCenter);

        labelDEFENCE = new QLabel(gridLayoutWidget_2);
        labelDEFENCE->setObjectName(QStringLiteral("labelDEFENCE"));

        gridLayout_2->addWidget(labelDEFENCE, 5, 0, 1, 1, Qt::AlignHCenter);


        retranslateUi(shopscene);

        QMetaObject::connectSlotsByName(shopscene);
    } // setupUi

    void retranslateUi(QWidget *shopscene)
    {
        shopscene->setWindowTitle(QApplication::translate("shopscene", "Form", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(3, QApplication::translate("shopscene", "DAMAGE OUT", 0));
        ___qtreewidgetitem->setText(2, QApplication::translate("shopscene", "DAMAGE IN", 0));
        ___qtreewidgetitem->setText(1, QApplication::translate("shopscene", "PRICE", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("shopscene", "NAME", 0));
        label_6->setText(QApplication::translate("shopscene", "Helmet:", 0));
        labelWEPON->setText(QApplication::translate("shopscene", "NONE", 0));
        label_7->setText(QApplication::translate("shopscene", "First wepon:", 0));
        label_8->setText(QApplication::translate("shopscene", "Defence:", 0));
        labelHELMET->setText(QApplication::translate("shopscene", "NONE", 0));
        labelDEFENCE->setText(QApplication::translate("shopscene", "NONE", 0));
    } // retranslateUi

};

namespace Ui {
    class shopscene: public Ui_shopscene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPSCENE_H
