#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:

public slots:

private slots:
    void on_exitGame_clicked();

    void on_startGame_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
