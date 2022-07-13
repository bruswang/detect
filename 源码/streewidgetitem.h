#ifndef STREEWIDGETITEM_H
#define STREEWIDGETITEM_H

#include <QObject>
#include <QTreeWidgetItem>
#include "My_Struct.h"
#include "tooltreewidgetitem.h"
#include "MyTool/my_tool.h"

class STreeWidgetItem :public QObject ,public QTreeWidgetItem
{
    Q_OBJECT
public:
    STreeWidgetItem(QTreeWidget *parent=nullptr);
    ~STreeWidgetItem();
    void SetInputPara(_DBFinfo db);
    int GetParaSize();
    _DBFinfo GetParaData();
    void ToolRun();
    void GetFileData(int index);
    void AddTool(ToolTreeWidgetItem *tool);
    QVector<ToolTreeWidgetItem*> GetToolcector();
    void SetToolText(ToolTreeWidgetItem *tools);
signals:
    void RunReslut();
private:
    My_Tool *tool;
    QVector<ToolTreeWidgetItem*> my_vector;

};

#endif // STREEWIDGETITEM_H
