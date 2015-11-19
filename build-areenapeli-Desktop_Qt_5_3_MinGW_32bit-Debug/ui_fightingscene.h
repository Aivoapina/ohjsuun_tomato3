/********************************************************************************
** Form generated from reading UI file 'fightingscene.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIGHTINGSCENE_H
#define UI_FIGHTINGSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include <qquickwidget.h>

QT_BEGIN_NAMESPACE

class Ui_FightingScene
{
public:
    QGridLayout *gridLayout;
    QQuickWidget *qmlView;

    void setupUi(QWidget *FightingScene)
    {
        if (FightingScene->objectName().isEmpty())
            FightingScene->setObjectName(QStringLiteral("FightingScene"));
        FightingScene->resize(1000, 700);
        gridLayout = new QGridLayout(FightingScene);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        qmlView = new QQuickWidget(FightingScene);
        qmlView->setObjectName(QStringLiteral("qmlView"));
        qmlView->setEnabled(true);
        qmlView->setResizeMode(QQuickWidget::SizeRootObjectToView);

        gridLayout->addWidget(qmlView, 0, 0, 1, 1);


        retranslateUi(FightingScene);

        QMetaObject::connectSlotsByName(FightingScene);
    } // setupUi

    void retranslateUi(QWidget *FightingScene)
    {
        FightingScene->setWindowTitle(QApplication::translate("FightingScene", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class FightingScene: public Ui_FightingScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIGHTINGSCENE_H
