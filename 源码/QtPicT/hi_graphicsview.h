#ifndef HI_GRAPHICSVIEW_H
#define HI_GRAPHICSVIEW_H

#include <QBoxLayout>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <qevent.h>
#include <QPainter>
#include <QRect>
#include <QGraphicsSceneMouseEvent>

class HI_ImageBox;

class MyGraphicsPixmapItem:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
    public: explicit MyGraphicsPixmapItem(QGraphicsItem * parent = 0);

    int TypeK; //框选形状
    int CirSizeR;
    QPoint pint;     // 当前点位
signals:
    void sendPoint(QPoint x1,QPoint y1,QPoint x2,QPoint y2);
    void CirIsClied(int value);

public slots:
    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

//virtual void paintEvent(QPaintEvent * event);


private:

};
#if 0
class ImageItem:public QGraphicsItem
{
    Q_OBJECT

public:
    ImageItem(QGraphicsItem *parent = 0);
    ~ImageItem();
    ImageItem(const QPixmap& pixmap, QGraphicsItem* parent);

    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    };
#endif

class HI_GraphicsView:public QGraphicsView
{
    Q_OBJECT

public:
    HI_GraphicsView(QWidget *parent = 0);
    ~HI_GraphicsView();

    void Init(HI_ImageBox * imageBox){m_imageBox = imageBox;}

    void SetImage(const QImage & image);

protected:
    virtual void wheelEvent(QWheelEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void mouseDoubleClickEvent(QMouseEvent *event) override;

    virtual void paintEvent(QPaintEvent * event);

public slots:
    void ZoomIn();
    void ZoomOut();
    void Zoom(float scaleFactor);
    void Translate(QPointF delta);




private:
    bool m_isTranslate;
    QPoint m_lastMousePos;
    HI_ImageBox * m_imageBox;
    QGraphicsScene * m_scene;

    QGraphicsScene * m_scene_Cir; // 第二张画布
    QGraphicsPixmapItem * m_imageItem;

};

#endif // HI_GRAPHICSVIEW_H
