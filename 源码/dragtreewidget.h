#ifndef DRAGTREEWIDGET_H
#define DRAGTREEWIDGET_H

#include <QObject>
#include <QTreeWidget>

class DragTreeWidget:public QTreeWidget
{
    Q_OBJECT
public:
    DragTreeWidget(QWidget *parent);
    ~DragTreeWidget();

private:
    void init();
protected:
    void mouseDoubleClickEvent(QMouseEvent *ev)override;


};

#endif // DRAGTREEWIDGET_H
