#ifndef MOUSESIZE_H
#define MOUSESIZE_H
#include <QMouseEvent>
#include <QWidget>
#include <QPainter>
#include <QRect>
//#include <QtPicT/hi_imagebox.h>


namespace Ui {
class MouseSize;
}

class MouseSize : public QWidget
{
    Q_OBJECT

public:
    explicit MouseSize(QWidget *parent = 0,int heightsize = 0,int widthsize = 0);
    ~MouseSize();
#if 1
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent * event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event); // 重新鼠标释放函数

protected:
    void wheelEvent(QWheelEvent *event);

#endif
private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void on_comboBox_2_currentIndexChanged(int index);

signals:
    void sendPoint(QPoint x1,QPoint y1,QPoint x2,QPoint y2);
    void CirIsClied(int value);

private:
    Ui::MouseSize *ui;
    //HI_ImageBox m_imageBox;
    int TypeK; //框选形状
    int CirSizeR;
    QPoint	m_startPT;
    QPoint	m_endPT;
};

#endif // MOUSESIZE_H
