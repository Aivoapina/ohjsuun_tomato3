#include "myqframe.h"
#include "ui_myqframe.h"

myQFrame::myQFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::myQFrame)
{
    ui->setupUi(this);
}

myQFrame::~myQFrame()
{
    delete ui;
}

void myQFrame::paivita()
{

}

void myQFrame::mousePressEvent(QMouseEvent *e)
{
    if( children().size() != 0 ){
        emit clicked();
    }
}
