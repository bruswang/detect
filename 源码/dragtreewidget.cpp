#include "QtGuiDrag.h"
#include "dragtreewidget.h"
#include "global.h"
#include "tooltreewidgetitem.h"
#include <QDrag>
#include <QMimeData>
#include <QMouseEvent>
#include <QDebug>

#pragma execution_character_set("utf-8")
DragTreeWidget::DragTreeWidget(QWidget *parent)
    : QTreeWidget(parent) {
    init();
    this->setHeaderHidden(true);
    setDragDropMode(QAbstractItemView::InternalMove);
    setDragEnabled(true);
}

DragTreeWidget::~DragTreeWidget() {

}

void DragTreeWidget::init() {
    for(int i=0;i<3;i++){
        ToolTreeWidgetItem* topItem = new ToolTreeWidgetItem;
        topItem->setText(0, "工具"+QString::number(i));
        topItem->setExpanded(true);
        this->addTopLevelItem(topItem);

    }
//    QTreeWidgetItem* topItem = new QTreeWidgetItem(this);
//      topItem->setText(0, QStringLiteral("组件B"));

//      topItem->setExpanded(true);

//      QTreeWidgetItem* topItem2 = new QTreeWidgetItem(this);
//      topItem2->setText(0, QStringLiteral("组件A"));

}



void DragTreeWidget::mouseDoubleClickEvent(QMouseEvent*ev){

    if(ev->button()==Qt::LeftButton){
        ToolTreeWidgetItem *item =(ToolTreeWidgetItem*) itemAt(ev->pos()); //当前位置的item
        if(item!=nullptr){
            qDebug()<<"im  here 11";
            F_ShowGroup->AddTool_Tree(item);
        }
    }
}
