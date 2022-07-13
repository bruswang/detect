#include "DropTreeWidget.h"
#include "diacrllist.h"
#include "streewidgetitem.h"
#include "global.h"
#include "diasetpro.h"
#include <QTreeWidgetItem>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QStyleFactory>
#include <QDebug>
#include <QMenu>
#include <QPushButton>

DropTreeWidget::DropTreeWidget(QWidget *parent)
    : QTreeWidget(parent) {

    init();

}

DropTreeWidget::~DropTreeWidget() {

}

void DropTreeWidget::dragEnterEvent(QDragEnterEvent *event) {
    if (event->mimeData()->hasFormat("Data/name")){
        if (event->source() == this){
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void DropTreeWidget::dropEvent(QDropEvent *event) {
    if (event->mimeData()->hasFormat("Data/name")) {
        //获取拖拽时设置的数据
        QByteArray itemData = event->mimeData()->data("Data/name");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QString text;
        dataStream >>text;

        QTreeWidgetItem *item = itemAt(event->pos()); //当前位置的item
        if (item == nullptr) {
            return;
        }
        QTreeWidgetItem* newItem = new QTreeWidgetItem(item);
        newItem->setText(0, text);
        newItem->setData(0,Qt::UserRole,text);
        item->setExpanded(true);

        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void DropTreeWidget::mousePressEvent(QMouseEvent *ev)
{

    if(ev->button()==Qt::RightButton)
    {

        QTreeWidgetItem *item = itemAt(ev->pos()); //当前位置的item
        if (item == nullptr) {
            return;
        }

        QString name=item->data(0,Qt::UserRole).toString();

        qDebug()<<item->data(0,Qt::UserRole);


        if(name==QStringLiteral("任务")){
            //此处为任务父节点

            QMenu *popMenu =new QMenu(this);//定义一个右键弹出菜单
            QAction* deletetask = new QAction(QString::fromLocal8Bit("删除任务"));
            QAction* copytask = new QAction(QString::fromLocal8Bit("复制任务"));
            deletetask->setObjectName("deletetask");
            copytask->setObjectName("copytask");

            popMenu->addAction(deletetask);
            popMenu->addAction(copytask);

            connect(deletetask, SIGNAL(triggered()), this, SLOT(onDeletetask()));
            connect(copytask, SIGNAL(triggered()), this, SLOT(onCopytask()));

             popMenu->exec(QCursor::pos());

        }else if(name==QStringLiteral("工具")){
            //此处为工具节点
             qDebug()<<2;
            QMenu *popMenu =new QMenu();//定义一个右键弹出菜单
            QAction* deletetask = new QAction(QString::fromLocal8Bit("删除工具"));
            QAction* copytask = new QAction(QString::fromLocal8Bit("复制工具"));
            deletetask->setObjectName("deletetool");
            copytask->setObjectName("copytool");

            popMenu->addAction(deletetask);
            popMenu->addAction(copytask);

            connect(deletetask, SIGNAL(triggered()), this, SLOT(onDeleteTool()));
            connect(copytask, SIGNAL(triggered()), this, SLOT(onCopyTool()));
            popMenu->exec(QCursor::pos());
        }



    }

    if(ev->button()==Qt::LeftButton){
        QTreeWidgetItem *item = itemAt(ev->pos()); //当前位置的item
        if(item==nullptr){
            return;
        }
        qDebug()<<"item"<<item->text(0)<<item->isSelected();
        this->setCurrentItem(item);

        if(item->parent()!=nullptr){
            Output=item;
        }
    }


}

void DropTreeWidget::mouseDoubleClickEvent(QMouseEvent*ev){

    if(ev->button()==Qt::LeftButton){
        QTreeWidgetItem *item = itemAt(ev->pos()); //当前位置的item
        qDebug()<<"Double Click"<<item;
        if (item == nullptr) {
            return;
        }
        if(item->parent()!=nullptr){

            STreeWidgetItem *z=(STreeWidgetItem*)item;
            if(z->property("issource")==true&&z->property("task").toInt()>0){
                DiaSetPro* w=new DiaSetPro;
                w->SetStruct(z);
                w->show();
            }

        }else{
            return;
        }

    }
}


void DropTreeWidget::mouseReleaseEvent(QMouseEvent *ev)
{

    if(ev->button()==Qt::LeftButton)
    {
        QTreeWidgetItem *pCurrentItem = itemAt(ev->pos()); //当前位置的item
        if (pCurrentItem == NULL) {
            return;
        }
        if(pCurrentItem->parent()!=nullptr){
            if(pCurrentItem!=nullptr){
                QString strText = pCurrentItem->text(0);
                Input=pCurrentItem;
                if(Output==Input)
                {
                    Output=nullptr;
                    Input=nullptr;
                }else  if(Input==nullptr)
                {
                    Output=nullptr;
                    Input=nullptr;
                }else if(Output!=nullptr&&Input!=nullptr){
                    QString  out="   --》";
                    Output->setText(0,Output->text(0)+out);
                    Input->setText(0,Input->text(0)+"   《--"+Output->data(0,Qt::UserRole).toString());

                    Output=nullptr;
                    Input=nullptr;

                }
            }

        }
    }
}


void DropTreeWidget::ReloadFile_Camera(){
    if(My_Tree.size()!=0){
        QMap<int, STreeWidgetItem *>::iterator it1 = My_Tree.begin();

        for(; it1!=My_Tree.end(); ++it1)
        {
            if(it1.value()==NULL){
                it1.value()= new STreeWidgetItem(this);
                it1.value()->setText(0, QStringLiteral("任务")+QString::number(it1.key()));
                it1.value()->setData(0,Qt::UserRole,  QStringLiteral("任务"));
                it1.value()->setObjectName(QString::number(it1.key()));
                it1.value()->GetFileData(it1.key());
                it1.value()->setProperty("istask",QString::number(it1.key()));
                this->addTopLevelItem( it1.value());


                STreeWidgetItem * imgsource  = new STreeWidgetItem(this);
                imgsource->setText(0,QStringLiteral("图片源"));
                imgsource->setProperty("issource",true);
                imgsource->setProperty("istool",false);
                imgsource->setProperty("task",it1.key());
                imgsource->setData(0,Qt::UserRole, QStringLiteral("图片源"));
                it1.value()->addChild(imgsource);
                it1.value()->setExpanded(true);

            }

        }
        ReloadRead();

    }
}


void DropTreeWidget::ReloadRead(){
    if(My_Tree.size()!=0){
        QMap<int, STreeWidgetItem *>::iterator it1 = My_Tree.begin();

        for(; it1!=My_Tree.end(); ++it1)
        {
            if(it1.value()!=NULL){
                it1.value()->GetFileData(it1.key());
                _DBFinfo db=it1.value()->GetParaData();
                if(db.isUsing){
                    it1.value()->setHidden(false);
                }else{
                    it1.value()->setHidden(true);
                }
            }

        }

    }
}

void DropTreeWidget::init() {
    setDragDropMode(QAbstractItemView::InternalMove);
    this->setHeaderHidden(true);
    this->setStyle(QStyleFactory::create("windows"));
    this->setItemsExpandable(true);
    this->expandAll();
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    // 连接信号槽
    connect(this, SIGNAL(customContextMenuRequested(const QPoint &)),
            this, SLOT(onCustomContextMenuRequested(const QPoint&)));

}

void DropTreeWidget::onCustomContextMenuRequested(const QPoint &pt){




}


void DropTreeWidget::onDeletetask(){

}

void DropTreeWidget::onCopytask(){

}
void DropTreeWidget::onDeleteTool(){

}
void DropTreeWidget::onCopyTool(){

}

