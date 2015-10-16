#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow *window = new MainWindow(0);
    window->show();

    return app.exec();
}

