#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
#include "mainwindow.h"
#include <QTime>

int main(int argc, char *argv[])
{
    qsrand(QTime::currentTime().msec());

    QApplication app(argc, argv);
    MainWindow *window = new MainWindow(0);
    window->show();

    return app.exec();
}

