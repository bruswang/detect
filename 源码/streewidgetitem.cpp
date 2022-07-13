#include "streewidgetitem.h"
#include "global.h"
#include "mainwindow.h"
#include "My_Struct.h"
#include "tooltreewidgetitem.h"
#include "streewidgetitem.h"
#include <QMouseEvent>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QDebug>

#pragma execution_character_set("utf-8")
STreeWidgetItem::STreeWidgetItem(QTreeWidget *parent):QTreeWidgetItem()
{
    tool=new My_Tool();
}

STreeWidgetItem::~STreeWidgetItem()
{
    delete  tool;
    tool=NULL;
}

void STreeWidgetItem::SetInputPara(_DBFinfo db){

    tool->SetTaskDBF(db);

}
int STreeWidgetItem::GetParaSize(){
    return  tool->GetInpuParaSize();
}

_DBFinfo STreeWidgetItem::GetParaData(){
    return  tool->GetTaskDBF();
}

void  STreeWidgetItem::ToolRun(){
    tool->Run();
}


void STreeWidgetItem::GetFileData(int index){

    //从文件中去二进制数据
    QFile  fileName("./config/task/"+QString::number(index));
    if(!fileName.open(QIODevice::ReadOnly))
    {
        qDebug()<<"failed";
        return;
    }
    if(!fileName.exists()){
        return;
    }
    QDataStream in(&fileName);
    uint dataSize = sizeof(_DBFinfo);
    char* temp = new char[dataSize];
    in.readBytes(temp,dataSize);

    _DBFinfo dd;
    memcpy(&dd,temp,dataSize);

    tool->SetTaskDBF(dd);

    fileName.close();
    delete[] temp;

}


void  STreeWidgetItem::AddTool(ToolTreeWidgetItem *tool){
    ToolTreeWidgetItem *tools=new ToolTreeWidgetItem;
    tools->setProperty("istool",true);
    tools->setProperty("task",this->objectName().toInt());
    tools->setData(0,Qt::UserRole, "工具");
    this->addChild(tools);
    my_vector.append(tools);
    SetToolText(tools);
}

QVector<ToolTreeWidgetItem *> STreeWidgetItem::GetToolcector()
{
    return  my_vector;
}

void STreeWidgetItem::SetToolText(ToolTreeWidgetItem *tools){
    QString num="工具"+QString::number(my_vector.indexOf(tools)+1);
    tools->setText(0,num);
    tools->setProperty("key",my_vector.indexOf(tools));
}

