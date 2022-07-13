#ifndef DROPTREEWIDGET_H
#define DROPTREEWIDGET_H

#pragma once

#include "streewidgetitem.h"

#include <QTreeWidget>

class DropTreeWidget : public QTreeWidget {
    Q_OBJECT

public:
    DropTreeWidget(QWidget *parent);
    ~DropTreeWidget();

    void dragEnterEvent(QDragEnterEvent *event)override;
    void dropEvent(QDropEvent *event)override;
    void mousePressEvent(QMouseEvent *ev)override;
    void mouseReleaseEvent(QMouseEvent *ev)override;

    void mouseDoubleClickEvent(QMouseEvent *ev)override;
    void ReloadRead();

public slots:
    void ReloadFile_Camera();
private slots:
    void onCustomContextMenuRequested(const QPoint &pt);
    void onDeletetask();
    void onCopytask();
    void onDeleteTool();
    void onCopyTool();
private:
    void init();
    QTreeWidgetItem *Input;
    QTreeWidgetItem *Output;

};


#endif // DROPTREEWIDGET_H
