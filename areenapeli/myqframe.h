#ifndef MYQFRAME_H
#define MYQFRAME_H

#include <QWidget>
#include <QFrame>

namespace Ui {
class myQFrame;
}

class myQFrame : public QFrame
{
    Q_OBJECT

public:
    explicit myQFrame(QWidget *parent = 0);
    ~myQFrame();

    void mousePressEvent(QMouseEvent * e);

signals:
    void clicked();

private:
    Ui::myQFrame *ui;
};

#endif // MYQFRAME_H
