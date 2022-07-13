#include "hi_graphicsview.h"

#include <QGraphicsPixmapItem>

#include <QStyleOption>
#include "hi_imagebox.h"
#include <QDebug>
#include <QFileDialog>
#include <iostream>

#define COUT qDebug()<< __TIME__ << __FUNCTION__ << __LINE__ << " : "
using namespace std;
#if 0
ImageItem::ImageItem(QGraphicsItem *parent): ImageItem(parent)
{
}

ImageItem::ImageItem(const QPixmap& pixmap, QGraphicsItem* parent) : QGraphicsPixmapItem(pixmap, parent)
{

}

ImageItem::~ImageItem()
{
}

void ImageItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    //std::cout << "Item: (" << event->scenePos().x() << ", " << event->scenePos().y() << ')' << std::endl;
}
#endif

HI_GraphicsView::HI_GraphicsView(QWidget *parent):
    QGraphicsView(parent),
    m_isTranslate(false),
    m_scene(new QGraphicsScene()),
    m_imageItem(new QGraphicsPixmapItem())    // MyGraphicsPixmapItem   QGraphicsPixmapItem()
{
    m_scene->addItem(m_imageItem);
    setScene(m_scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setRenderHint(QPainter::Antialiasing);

    setSceneRect(INT_MIN/2, INT_MIN/2, INT_MAX, INT_MAX);
    setTransformationAnchor(QGraphicsView::AnchorViewCenter);
    centerOn(0, 0);
}

HI_GraphicsView::~HI_GraphicsView()
{
    m_scene->deleteLater();
    delete m_imageItem;
}

void HI_GraphicsView::SetImage(const QImage &image)
{
    m_imageItem->setPixmap(QPixmap::fromImage(image));
    QPoint newCenter(image.width() / 2 ,image.height()/2);

    //设置scene中心到图像中点
    centerOn(newCenter);
    show();
}

void HI_GraphicsView::wheelEvent(QWheelEvent *event)
{
    // 滚轮的滚动量
    QPoint scrollAmount = event->angleDelta();
    // 正值表示滚轮远离使用者放大负值表示朝向使用者缩小
    scrollAmount.y() > 0 ? ZoomIn() : ZoomOut();
}

void HI_GraphicsView::mouseMoveEvent(QMouseEvent *event)
{

    if(m_isTranslate)
    {
        //获取
        QPointF mouseDelta = event->pos()-m_lastMousePos;
        Translate(mouseDelta);
    }
    m_lastMousePos = event->pos();
    viewport()->update();

    QGraphicsView::mouseMoveEvent(event);
}

void HI_GraphicsView::paintEvent(QPaintEvent *event)
{
    #if 0
    QPainter painter(this->viewport());  //关键这一句
    QRectF rectangle1(pint.x()-CirSizeR, pint.y()-CirSizeR, CirSizeR*2, CirSizeR*2);
    if(TypeK ==1)
    {
        painter.drawEllipse(rectangle1);
    }
    else if(TypeK ==2)
    {
        painter.drawRect(rectangle1);
    }
    painter.end();
    QGraphicsView::paintEvent(event);
#elif 0
    qDebug("************MyView::paintEvent*****************");
       // QPainter painter;  //QWidget::paintEngine: Should no longer be called
        QPainter painter(this->viewport());  //关键这一句

        QLinearGradient ling(QPointF(70, 70), QPoint( 140, 140 ) );  //从起点到终点的渐变
        ling.setColorAt(0, Qt::blue);  //起点到中心要显示的颜色
        ling.setColorAt(1, Qt::green);
        ling.setSpread( QGradient::PadSpread );   //默认显示模式

        QBrush brush(ling);
        painter.setBrush(brush);
        painter.drawRect(0, 0, 200, 200);

        painter.end();
        QGraphicsView::paintEvent(event);
    #endif
}


void HI_GraphicsView::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
    {
        m_isTranslate = true;
        m_lastMousePos = event->pos();
    }
//    else if(event->button()==Qt::RightButton)
//    {
//        QPointF point = mapToScene(event->pos());
//        //只有点击图片时才发送
//        if (scene()->itemAt(point, transform()) != NULL)
//        {
//            emit m_imageBox->ImageClick(point.x(),point.y());
//        }
//    }
    //是否为鼠标左键按下

}

void HI_GraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
        m_isTranslate = false;

    QGraphicsView::mouseReleaseEvent(event);
}

void HI_GraphicsView::mouseDoubleClickEvent(QMouseEvent *event)
{
    centerOn(m_imageItem->pixmap().width()/2,m_imageItem->pixmap().height()/2);
    QGraphicsView::mouseDoubleClickEvent(event);
}

void HI_GraphicsView::ZoomIn()
{
    Zoom(1.1);
}

void HI_GraphicsView::ZoomOut()
{
    Zoom(0.9);
}

void HI_GraphicsView::Zoom(float scaleFactor)
{
    // 防止过小或过大
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
        return;

    scale(scaleFactor, scaleFactor);
}

void HI_GraphicsView::Translate(QPointF delta)
{
    int w = viewport()->rect().width();
    int h = viewport()->rect().height();
    QPoint newCenter(w / 2. - delta.x()+0.5,  h / 2. - delta.y()+0.5);
    centerOn(mapToScene(newCenter));
}

MyGraphicsPixmapItem::MyGraphicsPixmapItem(QGraphicsItem *parent)
{

#if 1
    TypeK = 1;
    CirSizeR = 20;
#endif
}

void MyGraphicsPixmapItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    pint=QPoint(event->pos().x(),event->pos().y());
    //QGraphicsView::update();
    COUT<<"pint:"<<pint;
    QPoint x1 = QPoint(event->pos().x()-CirSizeR,event->pos().y()-CirSizeR);
    QPoint y1 = QPoint(event->pos().x()-CirSizeR,event->pos().y()+CirSizeR);
    QPoint x2 = QPoint(event->pos().x()+CirSizeR,event->pos().y()-CirSizeR);
    QPoint y2 = QPoint(event->pos().x()+CirSizeR,event->pos().y()+CirSizeR);
    emit sendPoint(x1,y1,x2,y2);
    COUT<<"move";
    //QGraphicsView::mouseMoveEvent(event);
}

void MyGraphicsPixmapItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    COUT<<"press";
    if(event->button() == Qt::LeftButton){
        qDebug()<<"触发左键了";
        emit CirIsClied(CirSizeR);
    }
    //QGraphicsView::mousePressEvent(event);
}
# if 0
void MyGraphicsPixmapItem::paintEvent(QPaintEvent *event)
{
//    QPainter painter(NULL);  //关键这一句   this->viewport()
//    QRectF rectangle1(pint.x()-CirSizeR, pint.y()-CirSizeR, CirSizeR*2, CirSizeR*2);
//    if(TypeK ==1)
//    {
//        painter.drawEllipse(rectangle1);
//    }
//    else if(TypeK ==2)
//    {
//        painter.drawRect(rectangle1);
//    }
//    painter.end();

}
#endif
