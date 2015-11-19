#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fightingscene.h"
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQuickItem>
#include "map.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),
  ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow(){
    delete ui;
}


void MainWindow::on_exitGame_clicked()
{
    close();
}

void MainWindow::on_startGame_clicked()
{
    FightingScene *window = new FightingScene();
    window->show();
    close();
    /*
    QList<Tile> map;
    QString hero = "assets/bullmentula_ingame.png";
    QString location = "assets/grass_texture.jpg";

    for(int i = 0; i < 160; i++){
        if ( i == 5 ){
            map.append( Tile( hero, location ) );
            continue;
        }
        map.append( Tile( hero, location ) );
    }
    Map mapmodel;
    mapmodel.setMapModel(map);

    QQmlApplicationEngine yee;
    yee.rootContext()->setContextProperty("myModel", &mapmodel);
    yee.load(QUrl(QStringLiteral("qrc:/main.qml")));
    //QObject *item = view.rootObject();
    //QObject::connect(item, SIGNAL(qmlSignal(QString, int)),
    //                     &mapmodel, SLOT(moveKappa(QString,int)));
    view.show();
    close();*/
}
