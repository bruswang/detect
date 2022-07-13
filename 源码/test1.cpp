#include "test1.h"
#include "ui_test1.h"
#include <QDebug>
#include <QMouseEvent>
#include <QPainter>

QPoint pint;
test1::test1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::test1)
{
    ui->setupUi(this);
  this->setMouseTracking(true);
    ui->centralwidget->setMouseTracking(true);

}

test1::~test1()
{
    delete ui;
}

/***************************************
 * 函数名：initSerial
 * 槽函数
 * 功能:鼠标移动时执行的事件处理函数
****************************************/
void test1::mouseMoveEvent(QMouseEvent *event)
{
    qDebug()<<"this is mdrag = true";
    //计算label移动的新位置
    qDebug()<<"event->pos"<<event->pos().x()<<event->pos().y();

    pint=QPoint(event->pos().x(),event->pos().y());
    update();
    qDebug()<<"pint:"<<pint;
}

void test1::paintEvent(QPaintEvent * event){

    QPainter painter(this);
    QRectF rectangle1(pint.x()-40, pint.y()-40, 80.0, 80.0);
    painter.drawEllipse(rectangle1);
}
/***************************************
 * 函数名：initSerial
 * 槽函数
 * 功能://鼠标按下时执行的事件处理函数
****************************************/
void test1::mousePressEvent(QMouseEvent *event)
{
    //是否为鼠标左键按下
    if(event->button() == Qt::LeftButton){
    qDebug()<<"触发左键了";
    }
}
