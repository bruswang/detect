#include "mousesize.h"
#include "ui_mousesize.h"
#include <QDebug>
#include <QImage>
#include <QFileDialog>
#include <QPainter>
#include <QFileDialog>


int Sizenum;
extern QPoint pint;
extern bool IsBigPicK; // 大图框选
//extern QString filename;
MouseSize::MouseSize(QWidget *parent, int heightsize, int widthsize) :
    QWidget(parent),
    ui(new Ui::MouseSize)
{
    ui->setupUi(this);
    this->setMouseTracking(true);
    TypeK = 1;
    //ui->widget->setMouseTracking(true);
    for(int i = 0; i< 500; i++)
    {
        ui->comboBox->addItem(QString::number(i));
    }
    ui->comboBox->setCurrentText("20");
    Sizenum = 20;   // 初始滚轮大小
    CirSizeR =ui->comboBox->currentText().toInt();

//    m_imageBox.Init(ui->verticalLayout);
    QString filename1 = QFileDialog::getOpenFileName();
    qDebug()<<filename1;
    if(filename1.isEmpty())
        return;
    QImage img_old;
    if (img_old.load(filename1))
    {
        QSize IMAGE_SIZE(this->size());
        this->setAutoFillBackground(true);
        QPalette palette;
        //QPixmap fitpixmap = pixmap.scaled(with, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放

        palette.setBrush(QPalette::Background, QBrush(QPixmap::fromImage(img_old).scaled(IMAGE_SIZE)));//Qt::KeepAspectRatio,Qt::SmoothTransformation
        this->setPalette(palette);
    }
    //m_imageBox.SetImage(filename1);
    //  });
}

MouseSize::~MouseSize()
{
    delete ui;
}



void MouseSize::on_comboBox_currentTextChanged(const QString &arg1)
{
    CirSizeR =  ui->comboBox->currentText().toInt();
    Sizenum = CirSizeR;
}
void MouseSize::on_comboBox_2_currentIndexChanged(const QString &arg1)
{

}

void MouseSize::on_comboBox_2_currentIndexChanged(int index)
{
    if(index == 1)
    {
        TypeK = 2;
    }
    else
    {
        TypeK = 1;
    }
}
#if 1
/***************************************
 * 函数名：initSerial
 * 槽函数
 * 功能:鼠标移动时执行的事件处理函数
****************************************/
void MouseSize::mouseMoveEvent(QMouseEvent *event)
{
    //计算label移动的新位置
    pint=QPoint(event->pos().x(),event->pos().y());
    update();
    //qDebug()<<"pint:"<<pint;
    QPoint x1 = QPoint(event->pos().x()-CirSizeR,event->pos().y()-CirSizeR);
    QPoint y1 = QPoint(event->pos().x()-CirSizeR,event->pos().y()+CirSizeR);
    QPoint x2 = QPoint(event->pos().x()+CirSizeR,event->pos().y()-CirSizeR);
    QPoint y2 = QPoint(event->pos().x()+CirSizeR,event->pos().y()+CirSizeR);
    sendPoint(x1,y1,x2,y2);
}

void MouseSize::paintEvent(QPaintEvent * event){
    QPainter painter(this);
    QRectF rectangle1(pint.x()-CirSizeR, pint.y()-CirSizeR, CirSizeR*2, CirSizeR*2);
    if(TypeK ==1)
    {
        painter.drawEllipse(rectangle1);
    }
    else if(TypeK ==2)
    {
        painter.drawRect(rectangle1);
    }
}
/***************************************
 * 函数名：initSerial
 * 槽函数
 * 功能://鼠标按下时执行的事件处理函数
****************************************/
void MouseSize::mousePressEvent(QMouseEvent *event)
{
    //是否为鼠标左键按下
    if(event->button() == Qt::LeftButton){
        qDebug()<<"触发左键了";
        emit CirIsClied(CirSizeR);
    }
}

void MouseSize::mouseReleaseEvent(QMouseEvent *event)
{
//    if(IsBigPicK)
//    {
//        isPressedWidget = false; // 鼠标松开时，置为false
//        QRect rect(m_startPT, m_endPT);
//        sendPoint(m_startPT,m_startPT,m_endPT,m_endPT);
//        emit CirIsClied(CirSizeR);
//        IsBigPicK = false;
//    }
}

void MouseSize::wheelEvent(QWheelEvent *event)
{

    if(event->delta() > 0){
        qDebug()<<"num++"<<Sizenum++;
        ui->comboBox->setCurrentText(QString::number(Sizenum));
    }else{
        qDebug()<<"num--"<<Sizenum--;
        if(Sizenum<=1)
        {
            Sizenum = 1;
        }
        ui->comboBox->setCurrentText(QString::number(Sizenum));
    }
    CirSizeR =  Sizenum;
}


#endif
